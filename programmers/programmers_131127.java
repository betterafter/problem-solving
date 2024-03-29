import java.util.HashMap;

class Solution {
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        HashMap<String, Integer> m = new HashMap<>();
        for (int i = 0; i < want.length; i++) {
            m.put(want[i], number[i]);
        }

        // 시작 날짜를 각각 잡아준다.
        for (int i = 0; i <= discount.length - 10; i++) {
            HashMap<String, Integer> sm = new HashMap<>();
            // 시작 날짜로부터 10일 동안 할인 품목을 담아준다.
            for (int j = i; j < i + 10; j++) {
                String item = discount[j];
                int count = sm.getOrDefault(item, 0) + 1;
                sm.put(item, count);
            }

            // 이제 10일치를 담은 품목이 원하는 품목과 일치한지 체크한다.
            boolean isWork = true;
            for (String it : sm.keySet()) {
                if (sm.get(it) != m.get(it)) {
                    isWork = false;
                }
            }

            if (isWork) {
                answer++;
            }
        }

        return answer;
    }
}