#ifndef STUDENT_H
#define STUDENT_H

class student
{
friend class student_node;
private:
  char *name;
  int value;
public:
  student (const char *initial_name = 0,
           int initial_value = 0);
  student (const student &initial_student);
  ~student ();
  int init (const char *initial_name = 0,
            int initial_value = 0);
  student &operator= (const student &right_hand_side);
  int get_value () const
  {
    return value;
  }
  const char *get_name () const
  {
    return (const char *) name;
  }
  int operator< (const student &right_hand_side) const;
  int operator> (const student &right_hand_side) const;
  int operator== (const student &right_hand_side) const;
  int operator!= (const student &right_hand_side) const;


  void set_name (const char *new_name);
  void set_value (int value);
  void swap (student &student2);
};

#endif
