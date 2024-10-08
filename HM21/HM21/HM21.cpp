#include <iostream>
#include <vector>
#include <memory>

class Observer {
public:
    virtual void update(int state) = 0;
};

class Subject {
public:
    virtual void attach(std::shared_ptr<Observer> observer) = 0;
    virtual void detach(std::shared_ptr<Observer> observer) = 0;
    virtual void notify() = 0;
};

class ConcreteSubject : public Subject {
    int state;
    std::vector<std::shared_ptr<Observer>> observers;

public:
    void setState(int newState) {
        state = newState;
        notify();
    }

    int getState() const {
        return state;
    }

    void attach(std::shared_ptr<Observer> observer) override {
        observers.push_back(observer);
    }

    void detach(std::shared_ptr<Observer> observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify() override {
        for (const auto& observer : observers) {
            observer->update(state);
        }
    }
};

class ConcreteObserver : public Observer {
    int observerState;
    std::shared_ptr<ConcreteSubject> subject;

public:
    ConcreteObserver(std::shared_ptr<ConcreteSubject> subj) : subject(subj) {}

    void update(int state) override {
        observerState = state;
        std::cout << "Observer updated with state: " << observerState << std::endl;
    }
};

int main() {

    auto subject = std::make_shared<ConcreteSubject>();

    auto observer1 = std::make_shared<ConcreteObserver>(subject);
    auto observer2 = std::make_shared<ConcreteObserver>(subject);

    subject->attach(observer1);
    subject->attach(observer2);

    subject->setState(10);
    subject->setState(20);

    return 0;
}