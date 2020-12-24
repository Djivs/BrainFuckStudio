// Copyright 2020 Djivs
#include "mainwindow.h"
#include "ui_mainwindow.h"

// main window constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), dots_loading(":/res/img/loading.gif")
    , ui(new Ui::MainWindow) {
    // main window setup
    ui->setupUi(this);

    // toggle  theme and cell size options
    // so user know what is setted up as a default
    ui->actionDark->toggle();
    ui->action8_byte->toggle();


    // create thread for code executing
    thread = new QThread(this);
    connect(this, SIGNAL(destroyed()), thread, SLOT(quit()));


    // create code executer object
    worker = new CodeExecuter();

    // create timer
    timer = new QTimer;


    // connect signals

    // code executed -> end code exec
    connect(worker, SIGNAL(codeExecuted()), this, SLOT(end_code_execution()));
    // start operation ->run code
    connect(this, SIGNAL(startOperation()), worker, SLOT(runCode()));
    // to update output every X ms while code is running
    connect(timer, &QTimer::timeout,
        [this] () {ui->output->setText(worker->getOutput());});
    // start errors checking in different thread
    connect(this, SIGNAL(startErrorsChecking()), worker, SLOT(checkErrors()));
    // end errors checking
    connect(worker, SIGNAL(errorsChecked()), this, SLOT(end_errors_checking()));
    // start code converting to C
    connect(this, SIGNAL(startConvertToC()), worker, SLOT(convertToC()));
    // end code converting to C
    connect(worker, SIGNAL(codeConverted()), this, SLOT(end_code_converting()));

    // move worker to created thread and start it
    worker->moveToThread(thread);
    thread->start();




    // one liners





    // load/save from buffer
    connect(ui->actionLoad, &QAction::triggered, this,
        [this] () {return ui->prog->setText(buf);});
    connect(ui->actionSave, &QAction::triggered, this,
        [this] () {return buf = ui->prog->toPlainText();});

    // isnt it obvious what that function do?
    connect(ui->actionEnd_Code, &QAction::triggered, this,
        [this] () {return worker->setEndCode(1);});

    // load examples
    connect(ui->actionbeer_bf, &QAction::triggered, this,
        [this] () {loadFile("beer.bf");});
    connect(ui->actioncellsize_bf, &QAction::triggered, this,
        [this] () {loadFile("cellsize.bf");});
    connect(ui->actionhello_bf, &QAction::triggered, this,
        [this] () {loadFile("hello.bf");});
    connect(ui->actionmandelbrot_tiny_bf, &QAction::triggered, this,
        [this] () {loadFile("mandelbrot-tiny.bf");});
    connect(ui->actionmandelbrot_bf, &QAction::triggered, this,
        [this] () {loadFile("mandelbrot.bf");});
    connect(ui->actionpidigits_bf, &QAction::triggered, this,
        [this] () {loadFile("pidigits.bf");});


    // dynamic input update
    connect(ui->input, &QTextEdit::textChanged,
        [this] () {
        if (!worker->getEndCode()) {
           worker->setInput(ui->input->toPlainText());
        }
            });


    // clear QTextEdit's
    connect(ui->actionClear_input, &QAction::triggered,
        [this] () {ui->input->setText("");});
    // clear output requaries extra lines, so i left it in separated function
    connect(ui->actionClear_code, &QAction::triggered,
        [this] () {ui->prog->setText("");});


    // open terminal
    connect(ui->actionFast_exec, &QAction::triggered,
        [this] () {
        QString command = "xterm -e /bin/sh -c";
        command += "\"echo '";
        command += buf.toLatin1();
        command += "' >> buf.bf;";
        command += "bf buf.bf;";
        command += "exec /bin/sh\"";
        system(command);
        system("> buf.bf");});

    // setup syntax highlighting
    sh = std::make_unique<SyntaxHighlighter>(ui->prog->document());
}

MainWindow::~MainWindow() {
    // delete thread
    thread->wait(1000);
    thread->quit();

    // delete timer
    delete timer;

    // default
    delete ui;
}

void MainWindow::end_errors_checking() {
    // delete loading gif from the screen
    ui->label_loadimg->clear();
    ui->statusbar->showMessage("errors checked");
    ui->output->setText(worker->getOutput());
}

// function to end code execution
void MainWindow::end_code_execution() {
    // calculate finish date
    finish =  QDateTime::currentDateTime();

    // calculate execution time
    int secs = start.msecsTo(finish)/10;

    // stop loading gif
    dots_loading.stop();

    // delete loading gif from the screen
    ui->label_loadimg->clear();

    // change status
    QString msg = QString::number(static_cast<float>(secs/100.0));
    ui->statusbar->showMessage("executed in\n" + msg + 's');

    // set output
    ui->output->setText(worker->getOutput());

    // stop timer
    timer->stop();

    // end code
    worker->setEndCode(1);
}

// function to start code executing
void MainWindow::on_actionStart_Code_triggered() {
    // if code is still running, ignore
    if (!(worker->getEndCode()))
        return;
    // else

    // show loading
    ui->statusbar->showMessage("loading");
    ui->label_loadimg->setMovie(&dots_loading);
    dots_loading.start();

    // load code text to worker
    worker->setCode(ui->prog->toPlainText());

    // load input to worker
    worker->setInput(ui->input->toPlainText());

    // clear worker output
    worker->setOutput("");

    // start code
    worker->setEndCode(0);
    emit startOperation();

    // start timer
    timer->start(outFreq);

    // save starting time
    start =  QDateTime::currentDateTime();
}

// function to set dark color scheme
void MainWindow::on_actionDark_triggered() {
    // disable other scheme
    ui->actionLight->setChecked(0);

    // set all widgets and etc stylesheet
    QString style = "color: white; background-color: rgb(46, 52, 54)";
    ui->centralwidget->setStyleSheet(style);
    ui->menubar->setStyleSheet(style);
    ui->statusbar->setStyleSheet(style);
    ui->toolBar->setStyleSheet(style);
}

// function to set dark color scheme
// just as dark sheme set but with different colours
void MainWindow::on_actionLight_triggered() {
    ui->actionDark->setChecked(0);
    QString style = "color: black; background-color: AliceBlue";
    ui->centralwidget->setStyleSheet(style);
    ui->menubar->setStyleSheet(style);
    ui->statusbar->setStyleSheet(style);
    ui->toolBar->setStyleSheet(style);
}

// function to set cell size equals 8 bit
void MainWindow::on_action8_byte_triggered() {
    // disable other cell sizes actions
    ui->action16_byte->setChecked(0);
    ui->action32_byte->setChecked(0);
    // set max value 2^8
    worker->setMaxValue(255);
}

// same as previous, but with 16 bits
void MainWindow::on_action16_byte_triggered() {
    ui->action8_byte->setChecked(0);
    ui->action32_byte->setChecked(0);
    worker->setMaxValue(65535);
}

// same as previous, but with 32 bits
void MainWindow::on_action32_byte_triggered() {
    ui->action16_byte->setChecked(0);
    ui->action8_byte->setChecked(0);
    worker->setMaxValue(4294967295);
}

// function to view memory
void MainWindow::on_actionView_memory_triggered() {
    // create new window
    textWindow = new TextWindow(this);
    textWindow->show();

    // qstring to display
    QString list;
    // vars to print like this:
    /*
     * 1       &
     * 11      &
     * 111     &
     * 1111    &
     * 11111   &
     * 111111  &
    */

    // and not like this:
    /*
     * 1 &
     * 11 &
     * 111 &
     * 1111 &
     * 11111 &
     * 111111 &
    */
    int comp = 10;
    QString spaces = "     ";

    // vector with BF memory representation
    std::vector<int16> buf = worker->getLine();

    // for every cell
    for (int i = 0; i < 30000; i++) {
        // make string like this:
        // #<cell number> <spaces> <cell value> <cell value as char>
        list += '#' + QString::number(i) + spaces + QString::number(buf[i]);
        list += " " + static_cast<char>(buf[i]) + "\n";
        // to manage spaces
        if (i+1 == comp) {
            spaces.chop(1);
            comp *= 10;
        }
    }
    // set this text
    textWindow->drawText(list);
}

// function to start errors checking
void MainWindow::on_actionCheck_Errors_triggered() {
    // show loading
    ui->statusbar->showMessage("loading");
    ui->label_loadimg->setMovie(&dots_loading);
    dots_loading.start();

    // load code text to worker
    worker->setCode(ui->prog->toPlainText());

    // clear worker output
    worker->setOutput("");

    // start
    emit startErrorsChecking();
}

// function to change output font
void MainWindow::on_actionOutput_triggered() {
    // typical choose-font code from docs
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont(), this);
    if (ok)
        ui->output->setFont(font);
}

// function to change input font
// same as previous
void MainWindow::on_actionInput_triggered() {
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont(), this);
    if (ok)
        ui->input->setFont(font);
}

// function to change code buffer font
// same as prev
void MainWindow::on_actionCode_buffer_triggered() {
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont(), this);
    if (ok)
        ui->prog->setFont(font);
}

// function to app font
// same as prev
void MainWindow::on_actionSystem_triggered() {
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont(), this);
    if (ok) {
        ui->label_input->setFont(font);
        ui->label_output->setFont(font);
        ui->label_edit_code->setFont(font);
        ui->menubar->setFont(font);
        ui->statusbar->setFont(font);
    }
}

// function to save text from code buf to file
void MainWindow::on_actionSave_to_file_triggered() {
    // choose file using qfiledialog
    QString filename = QFileDialog::getOpenFileName
        (this, tr("Open File"), tr("Text files (*.txt *.b *.bf)"));

    // open choosen file and write here
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(ui->prog->toPlainText().toLatin1());
        file.close();
    }
}

// function to load text from file to code buf
void MainWindow::on_actionLoad_from_file_triggered() {
    // choose file using qfiledialog
    QString filename = QFileDialog::getOpenFileName
        (this, tr("Open File"), tr("Text files (*.txt *.b *.bf)"));
    // open choosen file
    QFile file(filename);
    // read from here
    if (file.open(QIODevice::ReadOnly)) {
        ui->prog->setText(file.readAll());
        file.close();
    }
}

// convert code to C
void MainWindow::on_actionto_C_triggered() {
    worker->setCode(ui->prog->toPlainText());
    emit startConvertToC();
}

// ...
void MainWindow::end_code_converting() {
    textWindow = new TextWindow(this);
    textWindow->show();
    textWindow->drawText(worker->getConvertedCCode());
}

// func to update frequency set
void MainWindow::on_actionOutput_uodate_frequency_triggered() {
    // typical qinput dialog int read
    bool ok;
    int newOutFreq = QInputDialog::getInt
        (this, tr("QInputDialog::getInt()"), tr("Output frequency:"),
            outFreq, 0, 100, 1, &ok);
    // if number is given, update outFreq var
    if (ok && newOutFreq > 0) {
        outFreq = newOutFreq;
        // if code is running, restart timer
        if (timer->isActive()) {
            timer->stop();
            timer->start(outFreq);
        }
     }
}

void MainWindow::on_actionClear_output_triggered() {
    ui->output->setText("");
    // if code is executing, output will be loaded full again from worker, so
    // we need ro clear worker's output too
    if (!worker->getEndCode())
        worker->setOutput("");
}

// function to open text-to-bf-code converting window
void MainWindow::on_actiontext_to_code_triggered() {
    // create new window
    textToBfWindow = new TextToBF(this);
    // show it
    textToBfWindow->show();
}

// function to delete comments and stuff from code
void MainWindow::on_actionMinify_code_triggered() {
    // result dtring
    QString minifiedCode = "";

    // string with commands
    QString commands = "+-<>[].,";

    // string with code to minify
    QString code = ui->prog->toPlainText();

    // scan every character in code
    for (int i = 0; i < code.size(); i++) {
        // if code[i] is one of BF commands, add it to minified code
        if (commands.contains(code[i]))
            minifiedCode += code[i];
    }

    // make code look square(1 line = 55 characters)
    for (int i = 54; i < minifiedCode.size(); i+=55)
        minifiedCode.insert(i, '\n');

    // create new text window and show minified code
    textWindow = new TextWindow;
    textWindow->show();
    textWindow->drawText(minifiedCode);
}

void MainWindow::loadFile(QString filename) {
    // create QFile
    QFile file(":/res/txt/" + filename);
    if (file.open(QIODevice::ReadOnly)) {
        ui->prog->setText(file.readAll());
        file.close();
    }
}




















