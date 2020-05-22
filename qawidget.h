#ifndef QAWIDGET_H
#define QAWIDGET_H

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QList>
#include <QPair>
#include <QWidget>
#include <QCheckBox>
#include <QProgressBar>

class QAWidget : public QWidget
{
    Q_OBJECT
public:
    using QAListT = QList<QPair<QString, QString>>;

    explicit QAWidget(
            const QAListT &qalist,
            QWidget *parent = nullptr
            );

    void refresh();

    void onTextChanged(const QString &);
    void onAnswerChecked(bool correctness);
    void onPreviousPushed();
    void onNextPushed();
    void onPreviousPressed();
    void onNextPressed();

    static const QAListT TEST_QALIST;

signals:
    void answerChecked(bool correctness);


private:
    QAListT::size_type current_index_;
    QAListT qalist_;

    QLabel *questionLabel_;
    QLineEdit *answerInput_;

    QPushButton *previousButton;
    QPushButton *nextButton;

    QCheckBox *circleCheckBox;
    QProgressBar *progressBar;

};

#endif // QAWIDGET_H
