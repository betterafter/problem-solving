import java.util.ArrayList;
import java.util.HashMap;

class node{

    String name;
    node parent;
    ArrayList<node> child;
    int money = 0;
    HashMap<String, node> rootMap = new HashMap<>();

    public node(){};

    public node(String name, node parent, ArrayList<node> child, int money){
        this.name = name;
        this.parent = parent;
        this.child = child;
        this.money = money;
    }
    

    void connect(String target, String c, node curr, node root){

        if(curr.name.equals(target)){
            node childNode = new node(c, curr, new ArrayList<>(), 0);
            curr.child.add(childNode); 
            root.rootMap.put(c, childNode);
            return;
        }

        if(curr.child.size() <= 0) return;

        for(int i = 0; i < curr.child.size(); i++){
            node n = curr.child.get(i);
            connect(target, c, n, root);
        }
    }

    node search(String target, node curr){

        node temp = curr;

        if(curr.name.equals(target)){
            return curr;
        }

        if(curr.child.size() <= 0) return null;

        node n;
        for(int i = 0; i < curr.child.size(); i++){
            n = search(target, curr.child.get(i));
            if(n != null) {curr = n; break;}
        }
        if(temp == curr) return null;
        else return curr;
    }

    void send(node curr, int value){

        if(value * 10 / 100 < 1){
            curr.money += value; return;
        }

        if(curr.parent == null) return;

        curr.money += value - value * 10 / 100;
        
        send(curr.parent, value * 10 / 100);
    }
}

class Solution {
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        int[] answer = {};

        node root = new node("-", null, new ArrayList<>(), 0);
        for(int i = 0; i < enroll.length; i++){
            root.connect(referral[i], enroll[i], root, root);
        }

        // 시간 초과 때문에 root에 HashMap<String, node> 로 매핑해서 조금 더 빠르게 찾게 만듬
        for(int i = 0; i < seller.length; i++){
            root.send(root.rootMap.get(seller[i]), amount[i] * 100);
            //root.send(root.search(seller[i], root), amount[i] * 100);
        }

        answer = new int[enroll.length];
        for(int i = 0; i < enroll.length; i++){
            answer[i] = root.search(enroll[i], root).money;
        }

        return answer;
    }
}



// for(int i = 0; i < seller.length; i++){
//     if(sellerMap.get(seller[i]) != null)
//         sellerMap.put(seller[i], sellerMap.get(seller[i]) + amount[i] * 100);
//     else
//     sellerMap.put(seller[i], amount[i] * 100);
    
// }

// Set set = sellerMap.keySet();
// Iterator iterator = set.iterator();
// while(iterator.hasNext()){
//     String key = (String)iterator.next();
//     root.send(root.search(key, root), sellerMap.get(key));
// }