#include "interface.h"
#include "common.h"

TInterface::TInterface(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Работа №5");
    setFixedSize(1000,500);

    a_name = new QLabel("a = ", this);
    a_name->setGeometry(100, 30, 20, 20);
    a_re = new QLineEdit(this);
    a_re->setGeometry(120, 30, 30, 20);
    a_delimiter = new QLabel("+ i ", this);
    a_delimiter->setGeometry(150, 30, 20, 20);
    a_im = new QLineEdit(this);
    a_im->setGeometry(170, 30, 30, 20);
    a_name->hide();
    a_re->hide();
    a_delimiter->hide();
    a_im->hide();

    write_mode = new QLabel("Введите an", this);
    write_mode->setGeometry(100, 10, 150, 20);
    write_mode->hide();

    an_name = new QLabel("a = ", this);
    an_name->setGeometry(100, 30, 20, 20);
    an_re = new QLineEdit(this);
    an_re->setGeometry(120, 30, 30, 20);
    an_delimiter = new QLabel("+ i ", this);
    an_delimiter->setGeometry(150, 30, 20, 20);
    an_im = new QLineEdit(this);
    an_im->setGeometry(170, 30, 30, 20);
    an_name->hide();
    an_re->hide();
    an_delimiter->hide();
    an_im->hide();

    pos_root_name = new QLabel("индекс", this);
    pos_root_name->setGeometry(100, 70, 60, 20);
    pos_root_val = new QLineEdit(this);
    pos_root_val->setGeometry(160, 70, 20, 20);
    pos_root_name->hide();
    pos_root_val->hide();

    x_name = new QLabel("x = ", this);
    x_name->setGeometry(100, 30, 20, 20);
    x_re = new QLineEdit(this);
    x_re->setGeometry(120, 30, 30, 20);
    x_delimiter = new QLabel("+ i ", this);
    x_delimiter->setGeometry(150, 30, 20, 20);
    x_im = new QLineEdit(this);
    x_im->setGeometry(170, 30, 30, 20);
    x_name->hide();
    x_re->hide();
    x_delimiter->hide();
    x_im->hide();

    new_size_name = new QLabel("Новый размер - ", this);
    new_size_name->setGeometry(100, 30, 120, 20);
    new_size_value = new QLineEdit(this);
    new_size_value->setGeometry(220, 30, 30, 20);
    new_size_name->hide();
    new_size_value->hide();

    value_btn = new QPushButton("Вычислить значение в x", this);
    value_btn->setGeometry(50, 250, 200, 30);
    change_an_btn = new QPushButton("Изменить an", this);
    change_an_btn->setGeometry(260, 250, 150, 30);
    print_btn = new QPushButton("Вывести полином", this);
    print_btn->setGeometry(420, 250, 150, 30);
    write_btn = new QPushButton("Ввести полином", this);
    write_btn->setGeometry(580, 250, 150, 30);
    change_size_btn = new QPushButton("Изменить размер", this);
    change_size_btn->setGeometry(740, 250, 150, 30);
    change_root_btn = new QPushButton("Изменить корень", this);
    change_root_btn->setGeometry(260, 210, 150, 30);

    submit_value_btn = new QPushButton("Применить", this);
    submit_value_btn->setGeometry(200, 150, 150, 30);
    submit_value_btn->hide();
    submit_an_btn = new QPushButton("Применить", this);
    submit_an_btn->setGeometry(200, 150, 150, 30);
    submit_an_btn->hide();
    submit_print_btn = new QPushButton("Применить", this);
    submit_print_btn->setGeometry(200, 150, 150, 30);
    submit_print_btn->hide();
    submit_write_btn = new QPushButton("Далее", this);
    submit_write_btn->setGeometry(200, 150, 150, 30);
    submit_write_btn->hide();
    submit_change_size_btn = new QPushButton("Применить", this);
    submit_change_size_btn->setGeometry(200, 150, 150, 30);
    submit_change_size_btn->hide();
    submit_change_root_btn = new QPushButton("Применить", this);
    submit_change_root_btn->setGeometry(200, 150, 150, 30);
    submit_change_root_btn->hide();

    print_mode = new QComboBox(this);
    print_mode->addItem("Классический");
    print_mode->addItem("Канонический");
    print_mode->setGeometry(100, 30, 130, 20);
    print_mode->hide();

    complex_mode = new QRadioButton("Комплексный режим", this);
    complex_mode->setGeometry(150, 320, 200, 50);
    double_mode = new QRadioButton("Вещественный режим", this);
    double_mode->setGeometry(350, 320, 200, 50);

    output = new QLabel(this);
    output->setGeometry(150, 400, 600, 50);

    connect(value_btn, SIGNAL(pressed()), this, SLOT(value()));
    connect(change_an_btn, SIGNAL(pressed()), this, SLOT(change_an()));
    connect(print_btn, SIGNAL(pressed()), this, SLOT(print()));
    connect(write_btn, SIGNAL(pressed()), this, SLOT(write()));
    connect(change_size_btn, SIGNAL(pressed()), this, SLOT(change_size()));
    connect(change_root_btn, SIGNAL(pressed()), this, SLOT(change_root()));
    connect(submit_an_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(submit_value_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(submit_print_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(submit_write_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(submit_change_size_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(submit_change_root_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
}

TInterface::~TInterface()
{
    delete value_btn;
    delete change_an_btn;
    delete print_btn;
    delete write_btn;
    delete change_size_btn;
    delete change_root_btn;

    delete submit_an_btn;
    delete submit_value_btn;
    delete submit_print_btn;
    delete submit_write_btn;
    delete submit_change_size_btn;
    delete submit_change_root_btn;

    delete print_mode;

    delete a_name;
    delete a_delimiter;
    delete a_re;
    delete a_im;

    delete write_mode;

    delete x_name;
    delete x_delimiter;
    delete x_re;
    delete x_im;

    delete an_name;
    delete an_delimiter;
    delete an_re;
    delete an_im;

    delete new_size_name;
    delete new_size_value;

    delete complex_mode;
    delete double_mode;

    delete output;
}

void TInterface::value()
{
    output->setText("");
    x_name->show();
    x_re->show();
    x_delimiter->show();
    x_im->show();
    submit_value_btn->show();
}

void TInterface::print()
{
    output->setText("");
    print_mode->show();
    submit_print_btn->show();
}

void TInterface::change_an()
{
    output->setText("");
    an_name->show();
    an_re->show();
    an_delimiter->show();
    an_im->show();
    submit_an_btn->show();
}

void TInterface::change_size()
{
    output->setText("");
    new_size_name->show();
    new_size_value->show();
    submit_change_size_btn->show();
}

void TInterface::change_root()
{
    output->setText("");
    a_name->show();
    a_re->show();
    a_delimiter->show();
    a_im->show();
    pos_root_name->show();
    pos_root_val->show();
    submit_change_root_btn->show();
}

void TInterface::write()
{
    QString s = write_mode->text();
    if (s == "Введите an" && a_re->text() == "")
    {
        output->setText("");
        submit_write_btn->show();
        a_name->show();
        a_re->show();
        a_delimiter->show();
        a_im->show();
        write_mode->show();
    }
}

void TInterface::formRequest()
{
    QString msg;
    if (complex_mode->isChecked())
        msg << QString().setNum(COMPLEX_MODE);
    else
        msg << QString().setNum(DOUBLE_MODE);
    QPushButton *btn = (QPushButton*)sender();
    if (btn == submit_value_btn)
    {
        msg << QString().setNum(VALUE_REQUEST);
        if (complex_mode->isChecked())
            msg << x_re->text() << x_im->text();
        else msg << x_re->text();
    }
    if (btn == submit_print_btn)
    {
        if (print_mode->currentText() == "Классический")
            msg << QString().setNum(PRINT_CLASSIC_REQUEST);
        else
            msg << QString().setNum(PRINT_CANONIC_REQUEST);
    }
    if (btn == submit_an_btn)
    {
        msg << QString().setNum(CHANGE_AN_REQUEST);
        if (complex_mode->isChecked())
            msg << an_re->text() << an_im->text();
        else
            msg << an_re->text();
    }
    if (btn == submit_change_size_btn)
    {
        msg << QString().setNum(CHANGE_SIZE_REQUEST);
        msg << new_size_value->text();
    }
    if (btn == submit_change_root_btn)
    {
        msg << QString().setNum(CHANGE_ROOT_REQUEST);
        if (complex_mode->isChecked())
            msg << a_re->text() << a_im->text();
        else
            msg << a_re->text();
        msg << pos_root_val->text();
    }
    if (btn == submit_write_btn)
    {
        QString s = write_mode->text();
        int i = 0;
        if (s == "Введите an" && a_re->text() != "")
        {
            msg << QString().setNum(CHANGE_POL_AN_REQUEST);
            if (complex_mode->isChecked())
                msg << a_re->text() << a_im->text();
            else
                msg << a_re->text();
            write_mode->setText("Введите корень 1");
            a_re->setText("");
            a_im->setText("");
        }
        if (s != "Введите an")
        {
            s.remove(0, 15);
            i = s.toInt();
            msg << QString().setNum(CHANGE_POL_ROOTS_REQUEST);
            if (complex_mode->isChecked())
                msg << a_re->text() << a_im->text();
            else
                msg << a_re->text();
            msg << QString().setNum(i-1);
            s = "Введите корень ";
            s += QString().setNum(i+1);
            write_mode->setText(s);
            a_re->setText("");
            a_im->setText("");
        }
    }
    emit request(msg);
}

void TInterface::answer(QString msg)
{
    QString text;
    int p = msg.indexOf(separator);
    int t = msg.left(p).toInt();
    msg = msg.mid(p+1,msg.length()-p-2);
    switch (t)
    {
        case VALUE_ANSWER:
            text = "p";
            p = msg.indexOf(separator);
            text += msg.left(p);
            text += " = ";
            text += msg.right(msg.length()-p-1);
            output->setText(text);
            x_name->hide();
            x_re->hide();
            x_delimiter->hide();
            x_im->hide();
            submit_value_btn->hide();
            break;
        case PRINT_ANSWER:
            text = "p(x) = ";
            text += msg;
            output->setText(text);
            print_mode->hide();
            submit_print_btn->hide();
            break;
        case CHANGE_POL_ANSWER:
            a_re->setText("");
            a_im->setText("");
            break;
        case CHANGE_LAST_ANSWER:
            new_size_name->hide();
            new_size_value->hide();
            new_size_value->setText("");
            submit_change_size_btn->hide();
            a_name->hide();
            a_re->hide();
            a_re->setText("");
            a_delimiter->hide();
            a_im->hide();
            a_im->setText("");
            pos_root_name->hide();
            pos_root_val->hide();
            pos_root_val->setText("");
            submit_change_root_btn->hide();
            an_name->hide();
            an_re->hide();
            an_re->setText("");
            an_delimiter->hide();
            an_im->hide();
            an_im->setText("");
            submit_an_btn->hide();
            submit_write_btn->hide();
            write_mode->hide();
            write_mode->setText("Введите an");
            output->setText("Полином изменен");
            break;
        default: break;
    }
}
