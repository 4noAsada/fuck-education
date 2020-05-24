#ifndef QAWIDGET_H
#define QAWIDGET_H

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QList>
#include <QPair>
#include <QWidget>
#include <QCheckBox>
#include <QSlider>
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
    void onPreviousClicked();
    void onNextClicked();
    void onShowAnswerCheckBoxStateChanged(int state);
    void onItemSelectionChanged();
    void onSliderValueChanged(int value);

    static const PureQAListT TEST_QALIST;

signals:
    void answerChecked(bool correctness);


private:
    QAListT::size_type current_index_;
    QAListT qalist_;

    QLabel *questionLabel_;
    QLabel *answerLabel;
    QLineEdit *answerInput_;

    QPushButton *previousButton;
    QPushButton *nextButton;

    QCheckBox *showAnswerCheckBox;

    QCheckBox *circleCheckBox;
    QSlider *sliderBar;

    QListWidget *listWidget;

};

#endif // QAWIDGET_H
