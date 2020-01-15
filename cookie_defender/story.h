#ifndef STORY_H
#define STORY_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

class Story : public QWidget
{
    Q_OBJECT
public:
    Story(QWidget *parent = nullptr);
signals:
    void finishStory(void);
};

#endif // STORY_H
