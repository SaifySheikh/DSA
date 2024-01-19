class Stack:
    def __init__(self) -> None:
        self.items=[]

    def is_empty(self):
        if len(self.items)==0:
            return True
        return False

    def is_full(self):
        N=5
        return len(self.items)==N  

    def pop(self):
        if not self.is_empty():
            self.items.pop()
        else:
            raise IndexError("Pop from an empty Stack")    

    def push(self,element):
        if not self.is_full():
            self.items.append(element)

        else:
            raise IndexError("push in a full stack")


    def peek(self):
        length=len(self.items)
        print(f"{self.items[length-1]}")    


    def display(self):
        print(f"{self.items}")       



stack=Stack()
stack.push(1)
stack.push(2)
stack.push(3)    


stack.display()


stack.pop()
stack.display()

stack.peek()
