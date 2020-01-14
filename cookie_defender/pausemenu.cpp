#include "pausemenu.h"

#include <QVBoxLayout>
#include <QHBoxLayout>


PauseMenu::PauseMenu(QWidget *parent,int musicVolume,int soundsEffectVolume): QWidget(parent)
{
    resume = new QPushButton(tr("&Resume"));
    restart = new QPushButton(tr("Re&start"));
    encyclo = new QPushButton(tr("&Encyclopedia"));
    exit = new QPushButton(tr("To &main menu"));
    sounds = new SoundBoxes(nullptr,musicVolume,soundsEffectVolume,1);
    soundEnemyTP = new QMediaPlayer;
    soundMoney = new QMediaPlayer;
    soundGameWin = new QMediaPlayer;
    soundGameOver = new QMediaPlayer;
    soundEnemyTP->setMedia(QUrl("qrc:/sounds/enemyTP.wav"));
    soundMoney->setMedia(QUrl("qrc:/sounds/money.wav"));
    soundGameWin->setMedia(QUrl("qrc:/sounds/gameWin.wav"));
    soundGameOver->setMedia(QUrl("qrc:/sounds/gameOver.wav"));
    connect(sounds->sfx,&QSlider::valueChanged,this,[=](int value){
        soundEnemyTP->setVolume(value);
        soundMoney->setVolume(value);
        soundGameWin->setVolume(value);
        soundGameOver->setVolume(value);
    });
    QVBoxLayout *vLay = new QVBoxLayout;
    vLay->addStretch();
    vLay->addWidget(resume);
    vLay->addWidget(restart);
    vLay->addWidget(encyclo);
    vLay->addWidget(sounds);
    vLay->addWidget(exit);
    vLay->addStretch();

    QHBoxLayout *mainLay = new QHBoxLayout();
    mainLay->addStretch();
    mainLay->addLayout(vLay);
    mainLay->addStretch();
    setLayout(mainLay);
}
void PauseMenu::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape)
        emit resume->click();
}
void PauseMenu::manageMusic(bool play)
{
    play?sounds->music->play():sounds->music->stop();
    sounds->isPlaying=play;
}
