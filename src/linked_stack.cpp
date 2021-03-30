#include "linked_stack.hpp"

#include <stdexcept>  // logic_error

namespace itis {

void LinkedStack::Push(Element e) {
  // TODO: напишите здесь свой код ...
    auto* current_node = new SinglyNode(e, top_);
    top_ = current_node;
    size_++;
}

void LinkedStack::Pop() {
  if (top_ == nullptr) {
    throw std::logic_error("cannot pop out from empty stack");
  }
  // TODO: напишите здесь свой код ...

    SinglyNode *current_node = top_;
    top_ = top_->next;
    delete current_node;
    size_--;
}

void LinkedStack::Clear() {
  // TODO: напишите здесь свой код ...
    auto * node = top_;
    SinglyNode* next_node = nullptr;

    while (node != nullptr){
        next_node = node->next;
        delete node;
        node = next_node;
    }

    top_ = nullptr;
    size_ = 0;
}

// === РЕАЛИЗОВАНО ===

LinkedStack::~LinkedStack() {
  Clear();
}

std::optional<Element> LinkedStack::Peek() const {
  return top_ == nullptr ? std::nullopt : std::make_optional(top_->data);
}

bool LinkedStack::IsEmpty() const {
  return size_ == 0;
}

int LinkedStack::size() const {
  return size_;
}

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

std::ostream &operator<<(std::ostream &os, const LinkedStack &stack) {
  os << "size: " << stack.size_ << '\n';
  for (auto current_node = stack.top_; current_node != nullptr; current_node = current_node->next) {
    if (current_node == stack.top_) os << "[TOP] ";
    os << enum2str(current_node->data) << '\n';
  }
  return os;
}

}  // namespace itis