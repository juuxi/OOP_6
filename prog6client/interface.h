#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QRadioButton>

class TInterface : public QWidget
{
    Q_OBJECT

    QLabel *an_name, *an_delimiter;
    QLineEdit *an_re, *an_im;
    QLabel *write_mode;
    QLabel *a_name, *a_delimiter;
    QLineEdit *a_re, *a_im;
    QLabel *pos_root_name;
    QLineEdit *pos_root_val;
    QLabel *x_name, *x_delimiter;
    QLineEdit *x_re, *x_im;
    QLabel* new_size_name;
    QLineEdit* new_size_value;
    QPushButton* value_btn, *change_an_btn, *print_btn, *write_btn, *change_size_btn, *change_root_btn;
    QPushButton* submit_an_btn, *submit_value_btn, *submit_print_btn, *submit_write_btn, *submit_change_size_btn, *submit_change_root_btn;
    QComboBox* print_mode;
    QLabel* output;
    QRadioButton* complex_mode, *double_mode;

//    friend QString& operator<< (QString&,const QString&);

public:
    TInterface(QWidget *parent = 0);
    ~TInterface();

public slots:
    void answer(QString);
    void value();
    void print();
    void change_an();
    void change_size();
    void change_root();
    void write();

private slots:
    void formRequest();

signals:
    void request(QString);

};

#endif // INTERFACE_H
