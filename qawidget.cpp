#include "qawidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

const QAWidget::PureQAListT QAWidget::TEST_QALIST = {
    {"Hello", "World"},
    {"Human", "People"},
    {"Jerk", "Off"},
    {"Lost", "Found"},
    {"Moon", "Missing"},
    {"River", "Wind"},
    {"Long", "Short"},
    {"Dick", "Dirt"},
    {"Rain", "Snow"}
};


QAWidget::QAWidget(const QAWidget::PureQAListT &qalist, QWidget *parent)
    : QWidget(parent),
      current_index_(0)
{
    questionLabel_ = new QLabel();
    questionLabel_->setAlignment(Qt::AlignCenter);

    answerInput_ = new QLineEdit;
    answerInput_->setAlignment(Qt::AlignCenter);

    previousButton = new QPushButton("&Previous");
    nextButton = new QPushButton("&Next");
    circleCheckBox = new QCheckBox("Circle");

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(previousButton);
    buttonLayout->addWidget(circleCheckBox);
    buttonLayout->addWidget(nextButton);

    progressBar = new QProgressBar;
    progressBar->setMinimum(0);
    progressBar->setMaximum(qalist_.size() - 1);
    QHBoxLayout *progressLayout = new QHBoxLayout;
    progressLayout->addWidget(progressBar);

    listWidget = new QListWidget(this);
    for (const QPair<QString, QString> &x : qalist) {
        qalist_.append(
            {new QListWidgetItem(x.first, listWidget), x.second}
        );
    }

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addWidget(listWidget);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(questionLabel_);
    rightLayout->addWidget(answerInput_);
    rightLayout->addLayout(buttonLayout);
    rightLayout->addLayout(progressLayout);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    setLayout(mainLayout);
    setWindowTitle("QAWidget");

    connect(answerInput_, &QLineEdit::textChanged, this, &QAWidget::onTextChanged);
    connect(this, &QAWidget::answerChecked, this, &QAWidget::onAnswerChecked);
    connect(previousButton, &QPushButton::clicked, this, &QAWidget::onPreviousPushed);
    connect(nextButton, &QPushButton::clicked, this, &QAWidget::onNextPushed);
    connect(listWidget, &QListWidget::itemClicked, this, &QAWidget::onItemClicked);

    refresh();
}

void QAWidget::refresh()
{
    listWidget->setCurrentItem(qalist_[current_index_].first);
    questionLabel_->setText(qalist_[current_index_].first->text());
    answerInput_->clear();
    progressBar->setValue(current_index_);
}

void QAWidget::onTextChanged(const QString &text)
{
    emit answerChecked(text == qalist_[current_index_].second);
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

void QAWidget::onPreviousPushed()
{
    if (current_index_ > 0) {
        --current_index_;
        refresh();
    } else if (circleCheckBox->isChecked()) {
        current_index_ = qalist_.size() - 1;
        refresh();
    }
}

void QAWidget::onNextPushed()
{
    if (current_index_ < qalist_.size() - 1) {
        ++current_index_;
        refresh();
    } else if (circleCheckBox->isChecked()) {
        current_index_ = 0;
        refresh();
    }
}

void QAWidget::onItemClicked(QListWidgetItem *item)
{
    current_index_ = listWidget->currentRow();
    refresh();
}
