#ifndef _GRAPH_OBJECT_H
#define _GRAPH_OBJECT_H

class GraphObject {
public:
  GraphObject();
  ~GraphObject();
  int px;
  int py;
  int w;
  int h;
private:
  void object_callback();
};
#endif // _GRAPH_OBJECT_H
