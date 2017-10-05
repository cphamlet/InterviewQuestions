    #method for inserting a new node at the end of a Linked List   
    def insertAtEnd(self,data):
        newNode = Node()
        newNode.setData(data)
        if(self.head is None):
            self.head = newNode
            
        else:
            current = self.head
            while current.getNext() != None:
                current = current.getNext()
            current.setNext(newNode)
