/**
 * Class: CS3505
 * Authors: Tucker McKnight, Scott Stromberg, Ben Nelson, & Carlos Brenneisen
 * Team Amurica
 * Date: Spring 2011
 * 
 * A key object that represents a key on the keyboard. Includes the key's name (as a character),
 * as well as two images: one being a picture of the key when it is not pressed, the other when
 * it is depressed. A boolean ("pressed") determines which of these is appropriate to use.
 */

#ifndef __KEY_H_INCLUDED__
#define __KEY_H_INCLUDED__

#include <QtGui>
#include <string>

using namespace std;

class Key : public QPushButton
{
  
  Q_OBJECT
    public:

  /**
   * Constructor
   */
  Key() {}

  Key(string name, int primaryKeyCode, int secondaryKeyCode, QWidget *parent) : QPushButton(name.c_str(), parent) {
    this->name = name;
    this->primaryKeyCode = primaryKeyCode;
    this->secondaryKeyCode = secondaryKeyCode;
    this->pressed = false;
  }
  
  /**
   * Destructor
   */
  ~Key() {}
  
  /**
   * A character representing the character that this key is for
   */
  string name;
  
  /**
   * Represents if the key is currently depressed or not
   */
  bool pressed;

  /**
   * Qt primary and secondary key const.  This is used
   * when a keystroke is detected.
   */
  int primaryKeyCode, secondaryKeyCode;
};

#endif
