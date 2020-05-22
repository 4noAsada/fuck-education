#ifndef QAWIDGET_H
#define QAWIDGET_H

#include <QLabel>
#include <QLineEdit>

#include <QWidget>

class QAWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QAWidget(
            const QString &questionLabel_,
            const QString &answer_,
            QWidget *parent = nullptr
            );


    void onTextChanged(const QString &);
    void onAnswerChecked(bool correctness);

signals:
    void answerChecked(bool correctness);


private:
    QString answer_;
    QLabel *questionLabel_;
    QLineEdit *answerInput_;

};

#endif // QAWIDGET_H
