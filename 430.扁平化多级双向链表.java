/*
 * @lc app=leetcode.cn id=430 lang=java
 *
 * [430] 扁平化多级双向链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
};
*/


class Solution {
    class Pair<F, S> {
        private F first;
        private S second;

        public Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }

        public F getFirst() {
            return first;
        }

        public S getSecond() {
            return second;
        }
    }


    public Node flatten(Node head) {
        if (head == null) {
            return null;
        }
        // Node dummy = new Node();
        // dummy = flattenNodes(head).getSecond();
        // while(dummy.prev!= null){
        //     System.out.println(dummy.val);
        //     dummy = dummy.prev;
        // }

        return flattenNodes(head).getFirst();
    }

    public Pair<Node, Node> flattenNodes(Node head) {
        Node dummy = new Node();
        Node tmptail = dummy;
        while (head!= null) {
            tmptail.next = new Node();
            if(tmptail == dummy){
                tmptail.next.prev = null;
            }else{
                tmptail.next.prev = tmptail;
            }
            tmptail.next.val = head.val;
            tmptail = tmptail.next;


            if (head.child!= null) {
                Pair<Node, Node> childPair = flattenNodes(head.child);
                tmptail.next = childPair.getFirst();
                childPair.getFirst().prev = tmptail;
                tmptail = childPair.getSecond();
            }


            head = head.next;
        }
        return new Pair<>(dummy.next, tmptail);
    }
}
// @lc code=end

