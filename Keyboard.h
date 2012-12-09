/**
 * Class: CS3505
 * Authors: Tucker McKnight, Scott Stromberg, Ben Nelson, & Carlos Brenneisen
 * Team Amurica
 * Date: Spring 2011
 * 
 * A keyboard object that represents a dvorak keybaord.  This object contains an array of keys
 * which are displayed on the screen in a specific order.
 */
 
#ifndef __KEYBOARD_H_INCLUDED__
#define __KEYBOARD_H_INCLUDED__

#include <QtGui>
#include <QKeyEvent>

#include "Key.h"

class Keyboard : public QWidget
{
  Q_OBJECT
    public:

  /**
   * Constructor
   */
  Keyboard() {}

  /**
   * Destructor
   */
  ~Keyboard() {}

  /**
   * An array that holds all of the key objects.
   */
  Key *keys[61];

  /**
   * Toggles the pressed state of the button based on the 'press' param.
   */
  void toggleKey(const int keyCode, bool press);

  /**
   * Draws the keyboard to the screen.
   */
  void draw();

 protected:
  // Events
  void keyPressEvent(QKeyEvent *event);
  void keyReleaseEvent(QKeyEvent *event);
};

#endif
