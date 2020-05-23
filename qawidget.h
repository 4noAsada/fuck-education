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
#include <QListWidget>
#include <QListWidgetItem>

class QAWidget : public QWidget
{
    Q_OBJECT
public:
    using QAListT = QList<QPair<QListWidgetItem *, QString>>;
    using PureQAListT = QList<QPair<QString, QString>>;

    explicit QAWidget(
            const PureQAListT &qalist,
            QWidget *parent = nullptr
            );

    void refresh();

    void onTextChanged(const QString &);
    void onAnswerChecked(bool correctness);
    void onPreviousPushed();
    void onNextPushed();
    void onPreviousPressed();
    void onItemClicked(QListWidgetItem *item);

    static const PureQAListT TEST_QALIST;

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

    QListWidget *listWidget;

};

#endif // QAWIDGET_H
