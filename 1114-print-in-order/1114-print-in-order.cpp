class Foo {
public:
    Foo() {
        m2.lock(),m3.lock(); //keep m2 and m3 locked cause m1 should always print first
    }
    mutex m1,m2,m3;

    void first(function<void()> printFirst) {
        m1.lock();
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m1.unlock();
        m2.unlock();
    }

    void second(function<void()> printSecond) {
        m2.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        m2.unlock();
        m3.unlock();
    }

    void third(function<void()> printThird) {
        m3.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        m3.unlock();
    }
};