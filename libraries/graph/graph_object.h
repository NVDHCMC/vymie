#ifndef _GRAPH_OBJECT_H
#define _GRAPH_OBJECT_H

class GraphObject {
public:
  GraphObject(): px(0), py(0), w(0), h(0) {}
  virtual ~GraphObject() {}
protected:
  int px;
  int py;
  int w;
  int h;
  void object_callback();
};
#endif // _GRAPH_OBJECT_H
