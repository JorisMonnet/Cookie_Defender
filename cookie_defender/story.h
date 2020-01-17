#ifndef STORY_H
#define STORY_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

/**
* Class which inherits of QWidget, it contains the story of the game
*
* @author	Ugo Crucy,Joris Monnet,Adrien Paysant
*/

class Story : public QWidget
{
    Q_OBJECT
public:
    Story(QWidget *parent = nullptr);
signals:
    void finishStory(void);
};

#endif // STORY_H
