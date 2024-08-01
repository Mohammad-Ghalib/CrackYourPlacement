class twoStacks {
  public:
    int arr[100], top1, top2;
    twoStacks() {
        top1 = -1;
        top2 = 100;
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        arr[++top1] = x;
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        arr[--top2] = x;
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        return top1>-1? arr[top1--]: -1;
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        return top2<100? arr[top2++]: -1;
    }
};