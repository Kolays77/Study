#ifndef STUDENT_H
#define STUDENT_H

class student
{
friend class student_node;
private:
  char *name;
public:
  student (const char *initial_name = 0);
  ~student ();
  int init (const char *initial_name = 0);
  student &operator= (const student &right_hand_side);
  const char *get_name () const
  {
    return (const char *) name;
  }
  int operator< (const student &right_hand_side) const;

  void set_name (const char *new_name);
};

#endif
