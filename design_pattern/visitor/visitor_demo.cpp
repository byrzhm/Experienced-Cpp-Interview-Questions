#include <iostream>
#include <memory>
#include <vector>

class CarElement {
public:
  virtual void accept(class CarElementVisitor &) = 0;
};

class CarElementVisitor {
public:
  virtual void visit(class Wheel &) = 0;
  virtual void visit(class Engine &) = 0;
  virtual void visit(class Body &) = 0;
  virtual void visit(class Car &) = 0;
};

class Wheel : public CarElement {
public:
  Wheel(const std::string &name) : name_(name) {}
  const std::string &getName() const { return name_; }
  void accept(CarElementVisitor &visitor) override { visitor.visit(*this); }

private:
  std::string name_;
};

class Body : public CarElement {
public:
  void accept(CarElementVisitor &visitor) override { visitor.visit(*this); }
};

class Engine : public CarElement {
public:
  void accept(CarElementVisitor &visitor) override { visitor.visit(*this); }
};

class Car : public CarElement {
public:
  Car() {
    elements_.emplace_back(std::make_unique<Wheel>("front left"));
    elements_.emplace_back(std::make_unique<Wheel>("front right"));
    elements_.emplace_back(std::make_unique<Wheel>("back left"));
    elements_.emplace_back(std::make_unique<Wheel>("back right"));
    elements_.emplace_back(std::make_unique<Body>());
    elements_.emplace_back(std::make_unique<Engine>());
  }
  void accept(CarElementVisitor &visitor) override {
    for (auto &element : elements_) {
      element->accept(visitor);
    }
    visitor.visit(*this);
  }

private:
  std::vector<std::unique_ptr<CarElement>> elements_;
};

class CarElementDoVisitor : public CarElementVisitor {
public:
  void visit(Wheel &wheel) override {
    std::cout << "Kicking my " << wheel.getName() << " wheel\n";
  }
  void visit(Engine &engine) override { std::cout << "Starting my engine\n"; }
  void visit(Body &body) override { std::cout << "Moving my body\n"; }
  void visit(Car &car) override { std::cout << "Starting my car\n"; }
};

class CarElementPrintVisitor : public CarElementVisitor {
public:
  void visit(Wheel &wheel) override {
    std::cout << "Visiting " << wheel.getName() << " wheel\n";
  }
  void visit(Engine &engine) override { std::cout << "Visiting engine\n"; }
  void visit(Body &body) override { std::cout << "Visiting body\n"; }
  void visit(Car &car) override { std::cout << "Visiting car\n"; }
};

int main() {
  Car car;
  CarElementPrintVisitor printVisitor;
  car.accept(printVisitor);
  std::cout << "------------------------\n";
  CarElementDoVisitor doVisitor;
  car.accept(doVisitor);
  return 0;
}
