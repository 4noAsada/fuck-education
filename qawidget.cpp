#include "qawidget.h"
#include <QVBoxLayout>


QAWidget::QAWidget(const QString &question, const QString &answer, QWidget *parent)
    : QWidget(parent),
      answer_(answer)
{
    questionLabel_ = new QLabel(question);
    questionLabel_->setAlignment(Qt::AlignCenter);
    answerInput_ = new QLineEdit;
    answerInput_->setAlignment(Qt::AlignCenter);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(questionLabel_);
    layout->addWidget(answerInput_);

    setLayout(layout);
    setWindowTitle("QAWidget");

    connect(answerInput_, &QLineEdit::textChanged, this, &QAWidget::onTextChanged);
    connect(this, &QAWidget::answerChecked, this, &QAWidget::onAnswerChecked);
}

void QAWidget::onTextChanged(const QString &text)
{
    emit answerChecked(text == answer_);
}

void QAWidget::onAnswerChecked(bool correctness)
{
    QPalette palette;
    if (correctness == false) {
        palette.setColor(QPalette::Text, Qt::red);
    } else {
        palette.setColor(QPalette::Text, Qt::black);
    }
    answerInput_->setPalette(palette);
}
