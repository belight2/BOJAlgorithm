import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main {

    static class User {
        long id;
        int time;
        int counter;

        public User(long id, int time, int counter) {
            this.id = id;
            this.time = time;
            this.counter = counter;
        }
    }

    /**
     * point.1 계산이 동시에 끝났다면 빠른 번호부터 배정한다.
     * point.2 계산이 동시에 끝났다면 늦은 카운터 번호부터 나간다.
     * <p>
     * 동작 그럼 일단 Q 에 counter만큼 넣어 그리고 size가 다 찼다면 빼는데
     * (Q 빨리끝나는 순의 User순으로 정렬함 끝나는 숫자가 같다면 counter순 큰 순서로 정렬)
     */
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String[] setting = bf.readLine().split(" ");
        int n = Integer.parseInt(setting[0]);
        int counter = Integer.parseInt(setting[1]);

        Comparator<User> myUser = new Comparator<User>() {
            @Override
            public int compare(User o1, User o2) {
                if (o1.time != o2.time) {
                    return o1.time - o2.time;
                } else {
                    return o2.counter - o1.counter;
                }
            }
        };

        PriorityQueue<User> pq = new PriorityQueue<>(myUser); // 계산중인 시간이 짧은 순서대로의 queue
        PriorityQueue<Integer> cq = new PriorityQueue<>(); // 남아있는 카운터 번호
        Queue<User> q = new LinkedList<>(); // 줄서고있는 Queue

        long sum = 0;
        long outCount = 1;

        for (int i = 0; i < n; i++) {
            String[] input = bf.readLine().split(" ");
            q.add(new User( Long.parseLong(input[0]), Integer.parseInt(input[1]), 0));
        }


        for (int i = 1; i < counter+1; i++) {
            cq.add(i);
        }
        //손

        while (!pq.isEmpty() || !q.isEmpty()) {

            while (!q.isEmpty() && !cq.isEmpty()) {
                User inUser = q.remove();
                int c = cq.remove();
//                System.out.println(inUser.id+"번 손님이 "+ c+"번 카운터로 들어가십니다..");
                pq.add(new User(inUser.id, inUser.time, c));
            }
//            System.out.println();
            int time = pq.peek().time;
            for (User user : pq) {
                user.time -= time;
            }
//            System.out.println(time+"초가 지난 후......");
//            System.out.println();
            while (!pq.isEmpty() && pq.peek().time == 0) {
                User outUser = pq.remove();
                cq.add(outUser.counter);
//                System.out.println(outUser.id+"번 손님이 "+ outUser.counter+"번 카운터에서 나오십니다. "+outCount * outUser.id+" 나온 순서: "+outCount);
                sum += outCount * outUser.id;
                outCount++;

            }
//            System.out.print("남은 카운터 : ");
//            for(int a : cq){
//                System.out.print(a+" ");
//            }
//            System.out.println();
        }
//        System.out.println();
        System.out.println(sum);
    }


}