class List{
        private class node{
                Object value;
                node next;
                node previous;


                node(Object x){
                        value = x;
                        next = null;
                        previous = null;
                }
                
            
                public String toString(){
                    return "" + value;
        }

        }

        private node cursor;
        private node back;
        private node front;
        private int length;
        private int index;

        public List(){
                cursor=null;
                front=null;
                back=null;
                length=0;
                //index=-1;
        }


        public int index(){
                if(cursor==null){
                        return -1;
                }
                return index;
        }

        public int length(){
                return length;
        }

        public Object front(){
                if(length()>0){
                        return front.value;
                }
                throw new RuntimeException(
                        "Queue Error: front() called on empty Queue");
        }

        public Object back(){
                if(length()>0){
                        return back.value;
                }
                throw new RuntimeException(
                        "Queue Error: back() called on empty Queue");
        }

        public Object get(){
                if(length>0 && index()>=0){
                        return cursor.value;
                }
                return -1;
        }

        public boolean equals(Object L){
                node x1 = front;
                node x2 = ((List)L).front;
                while(x1!=null && x2!=null){
                        if(x1.value != x2.value){
                                return false;
                        }
                        x1=x1.next;
                        x2=x2.next;
                }
                return true;
        }

        public void clear(){
                cursor=null;
                front=null;
                back=null;
                length=0;
                index=-1;
        }

        public void moveFront(){
                if(front != null){
                        cursor = front;
                        index = 0;
                }
        }

        public void moveBack(){
                if(back!=null){
                        cursor = back;
                        index = length-1; //n-1//
                }
        }

        public void movePrev(){
                if(index()>0 && index()<= length()-1){
                        cursor = cursor.previous;
                }else{
                        cursor=null;
                }
        }

        /*public void moveNext(){
                int index = index();
                if(index >= 0 && index < length() - 1){
                    cursor = cursor.next;
            } else {
                    cursor = null;
                    System.out.println("moveNext null");

            }
    }*/

void moveNext(){
        if(cursor != null){
                if(index <=(length())-1){
                        cursor = cursor.next;
                        index++;
                }
                if(index == length()){
                        cursor =null;
                        index = -1;
                }
        }
}


    /*void moveNext()
    {
          if (cursor==back) cursor = null;
          if (cursor!=null) cursor = cursor.next;
  }*/

        /*public void moveNext(){
                if(cursor!=back){
                        cursor=cursor.next;
                        index++;
                }else{
                        index=-1;
                        cursor=null;
                }
        }*/

        /*public int getSize(){
                return matrix.length;
        }*/

        public void prepend(Object x){
                node n = new node(x);
                index++;
                length++;
                if(front!=null){
                        front.previous = n;
                        n.next = front;
                        front = n;
                }else{
                        back=n;
                }
                front=n;
        }

       /* public void append(Object x){
                node n = new node(x);
                index++;
                if(back!=null){
                        back.next=n;
                        n.previous=back;
                }else{
                        front = n;
                }
                back = n;
        }*/

        public void append(Object data){
        length++;
        index++;
        node temp = new node(data);
        if (back != null) {
            back.next = temp;
        } else {
            front = temp;
        }
        back = temp;
    }

        public void insertBefore(Object x){
                node n = new node(x);
                length++;
                n.next=cursor;
                if(length() >0 && index() >=0){
                        if(cursor.previous != null){
                                cursor.previous.next=n;
                        }else{
                                front = n;
                        }
                        cursor.previous = n;
                }
        }

        public void insertAfter(Object x){ //
                node n = new node(x);
                n.previous=cursor;
                n.next=cursor.next;
                if(length() > 0 && index() >=0){
                        length++;
                        if(cursor.next != null){
                                cursor.next.previous=n;
                        }else{
                                back=n;
                        }
                        cursor.next=n;
                }
        }

        public void deleteFront(){
                if(length()>0){
                        front=front.next;
                        if(front != null){
                                front.previous=null;
                        }
                        index--;

                        //length--;
                }
        }

        /*public void deleteBack(){
                if(length()>0){
                        back=back.previous;
                        back.previous=null;
                        index--;
                        //length--;
                }
        }*/

        public void deleteBack(){
                if (length() > 0){
                    length--;
                    if(cursor == back) cursor = null;
                    back = back.previous;
                    if(back != null) back.next = null;

                }
        }

/*        void delete() throws RuntimeException 
        {
          if(length()<1)
          {
               throw new RuntimeException(
                    "List Error: insertAfter() called on empty List");
       } 
       if(index()<0)
       {
               throw new RuntimeException(
                    "Cursor Error: insertAfter() called on null Index");
       }
       if(cursor==front) deleteFront();
       if(cursor==back) deleteBack();
       cursor.next.previous = cursor.previous;
       cursor.previous.next = cursor.next;
       cursor = null;
       length--;
}*/


        public void delete(){
                if(length()>0 && index()>=0){
                        length--;
                        cursor.value=-1;
                        cursor.next.previous = cursor.previous;
                        cursor.previous.next = cursor.next;
                }
                if(cursor==front){
                        deleteFront();
                }
                if(cursor==back){
                        deleteBack();
                }
        }

        public String toString(){
                node n = front;
                String s1="";
                while(n!=null){
                        s1=s1+n+" ";
                        n=n.next;
                }
                return s1;
        }

        /*List copy (){
                List newList= new List();
                node n = front;
                while(n!=null){
                        newList.append(n.value);
                        n=n.next;
                }
                return newList;
        }

        List concat(List x){
                List newList = copy();
                node n = x.front;
                while(n!=null){
                        newList.append(n.value);
                        n=n.next;
                }
                return newList;
        }*/
}
