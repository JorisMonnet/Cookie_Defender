#include "soundboxes.h"

#include <QGridLayout>
#include <QSlider>
#include <QLabel>
#include <QString>

const int VOL_MIN = 0;
const int VOL_MAX = 99;

SoundBoxes::SoundBoxes(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout *layout = new QGridLayout(this);
    sound = new QSlider(Qt::Horizontal, this);
    sound->setRange(VOL_MIN, VOL_MAX);
    sound->setSingleStep(1);

    sfx = new QSlider(Qt::Horizontal, this);
    sfx->setRange(VOL_MIN, VOL_MAX);
    sfx->setSingleStep(1);

    soundlb = new QLabel(QString::number(volume));
    sfxlb = new QLabel(QString::number(soundEffect));

    QLabel *soundtxt = new QLabel("Music");
    QLabel *sfxtxt = new QLabel("SFX");

    layout->addWidget(soundtxt, 0, 0);
    layout->addWidget(sound, 0, 1);
    layout->addWidget(soundlb, 0, 2);
    layout->addWidget(sfxtxt, 1, 0);
    layout->addWidget(sfx, 1, 1);
    layout->addWidget(sfxlb, 1, 2);

    connect(sound, &QSlider::valueChanged, this, &SoundBoxes::volumeChanged);
    connect(sfx, &QSlider::valueChanged, this, &SoundBoxes::sfxChanged);
}

void SoundBoxes::volumeChanged(int value)
{
    sound->setValue(value);
    soundlb->setText(QString::number(value));
}

void SoundBoxes::sfxChanged(int value)
{
    sfx->setValue(value);
    sfxlb->setText(QString::number(value));
}
