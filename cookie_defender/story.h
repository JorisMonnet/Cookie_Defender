#ifndef STORY_H
#define STORY_H

#include <QWidget>
#include <QPushButton>

class Story : public QWidget
{
    Q_OBJECT
public:
    explicit Story(QWidget *parent = nullptr);

signals:
    void finishStory();
};

#endif // STORY_H
