#include"avlNode.hpp"

avlNode::avlNode() :  next(nullptr), prev(nullptr), position(1) {}

avlNode::~avlNode()
{
    delete next;
    delete prev;
}