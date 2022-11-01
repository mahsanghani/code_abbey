//
// Created by Ahsan Ghani on 2022-10-31.
//
#ifndef REQUEST_H
#define REQUEST_H

enum class Direction { kUp = 0, kDown = 1 };

class Request {
private:
  int level;

public:
  Request(int l = 0) : level(l) {}
  int getLevel() const { return level; }
};

class ExternalRequest : public Request {
private:
  Direction direction;

public:
  ExternalRequest(){};
  ExternalRequest(int l, Direction d) : Request(l), direction(d) {}
  Direction getDirection() const { return direction; }
};

class InternalRequest : public Request {
public:
  InternalRequest(int l = 0) : Request(l) {}
};

#endif /* REQUEST_H */