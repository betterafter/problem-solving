package swea2022;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class UserSolution_d9_5 {

    int N, K, HASH = 200003;
    static User[] users = new User[1010];
    int base = 0;

    class User {
        int uID, cnt = 0;
        Mail head, tail;

        public User() {
            head = new Mail();
            tail = new Mail();

            init();
        }

        public void init() {
            head.next = tail;
            tail.prev = head;
        }

        public void add(Mail mail) {
            if (cnt >= K) {
                delete();
            }
            mail.prev = head;
            mail.next = head.next;
            head.next.prev = mail;
            head.next = mail;
            cnt++;
        }

        public void delete() {
            tail.prev.prev.next = tail;
            tail.prev = tail.prev.prev;
            cnt--;
        }
    }

    class Mail {
        Mail prev, next;
        char[] content;
    }

    public void init(int N, int K) {
        this.N = N;
        this.K = K;
        for (int i = 0; i < N; i++) {
            if (users[i] == null) users[i] = new User();
            else {
                users[i].cnt = 0;
                users[i].init();
            }
        }
    }

    // a : 카피할 대상, b : 카피될 대상
    void strcpy(char[] a, char[] b) {
        for (int i = 0; i < a.length; i++) {
            if (a[i] == '\0') {
                b[i] = a[i]; break;
            }
            b[i] = a[i];
        }
    }

    boolean strcmp(char[] a, char[] b) {
        for (int i = 0; a[i] != '\0'; i++) {
            if (a[i] != '\0' && b[i] == '\0') return false;
            if (a[i] == '\0' && b[i] != '\0') return false;
            if (a[i] != b[i]) return false;
        }
        return true;
    }

    boolean strcmp(char[] a, char[] b, int left, int right) {
        for (int i = 0; a[i] != '\0'; i++) {
            if (a[i] != b[left + i]) return false;
        }
        return true;
    }

    public void sendMail(char[] subject, int uID, int cnt, int[] rIDs) {
        for (int i = 0; i < cnt; i++) {
            char[] content = new char[subject.length];
            Mail mail = new Mail();
            strcpy(subject, content);
            mail.content = content;
            users[rIDs[i]].add(mail);
        }
    }

    int getCount(int uID) {
        return users[uID].cnt;
    }

    int deleteMail(int uID, char[] subject) {
        int cnt = 0;
        User user = users[uID];
        Mail curr = user.head.next;

        while (curr != user.tail) {
            if (strcmp(curr.content, subject)) {
                curr.prev.next = curr.next;
                curr.next.prev = curr.prev;
                user.cnt--;
                cnt++;
            } 
            curr = curr.next;
        }
        return cnt;
    }

    int searchMail(int uID, char[] text) {
        int cnt = 0;
        int chash = 0;
        User user = users[uID];
        Mail curr = user.head.next;

        int W = 0;
        for (int i = 0; i < text.length; i++) {
            if (text[i] == '\0') break;
            W++;
        }

        while (curr != user.tail) {
            int WW = curr.content.length;
            int phash = 0, power = 1;
            char[] content = curr.content;
            chash = 0;

            for (int i = 0; i <= WW - W; i++) {
                if (i == 0) {
                    for (int j = 0; j < W; j++) {
                        chash += text[W - 1 - j] * power;
                        phash += content[W - 1 - j] * power;
                        if (j != W - 1) power *= HASH;
                    }

                    if (chash == phash) {
                        if (content[W] == ' ' || content[W] == '\0') {
                            cnt++;
                            break;
                        }
                    }
                } else {
                    phash = HASH * (phash - content[i - 1] * power) + content[W - 1 + i];
                    if (phash == chash) {
                        if (content[W + i] == ' ' || content[W + i] == '\0') {
                            cnt++;
                            break;
                        }
                    }
                }
            }
            curr = curr.next;
        }
        return cnt;
    }
}

class Solution_d9_5 {

	private static BufferedReader br;
	private static UserSolution_d9_5 usersolution = new UserSolution_d9_5();
	
	private final static int INIT         = 0;
	private final static int SENDMAIL     = 1;
	private final static int GETCOUNT     = 2;
	private final static int DELETEMAIL   = 3;
	private final static int SEARCHMAIL   = 4;
	
	private final static int MAX_WORD     = 10000;
	
	private static char Word[][] = new char [MAX_WORD][11];
	private static char subjectStr[] = new char [200];
	private static int rids[] = new int [50];

	private static int U, W, minR, maxR, SW;

	private static int mSeed;
	private static int pseudo_rand()
	{
		mSeed = mSeed * 214013 + 2531011;
		return (mSeed >> 16) & 0x7FFF;
	}

	private static void make_string(int seed)
	{
		mSeed = seed;

		for (int i = 0; i < W; ++i) {
			int length = 5 + pseudo_rand() % 6;
			for (int k = 0; k < length; ++k) {
				Word[i][k] = (char)('a' + pseudo_rand() % 26);
			}
			Word[i][length] = '\0';
		}
	}

	private static void send_mail(int seed)
	{
		mSeed = seed;

		int pos = 0;
		int wcnt = 1 + pseudo_rand() % SW;
		for (int i = 0; i < wcnt; ++i) {
			int widx = pseudo_rand() % W;
			for (int k = 0; k < 10; ++k) {
				if (Word[widx][k] == '\0') break;
				subjectStr[pos++] = Word[widx][k];
			}
			subjectStr[pos++] = ' ';
		}
		subjectStr[pos - 1] = '\0';

		int uid = pseudo_rand() % U;
		int rcnt = minR + pseudo_rand() % (maxR - minR + 1);
		for (int i = 0; i < rcnt; ++i) {
			rids[i] = pseudo_rand() % U;
		}

		usersolution.sendMail(subjectStr, uid, rcnt, rids);
	}

	static int delete_mail(int uid, int seed)
	{
		mSeed = seed;
		
		int pos = 0;
		int wcnt = 1 + pseudo_rand() % SW;
		for (int i = 0; i < wcnt; ++i) {
			int widx = pseudo_rand() % W;
			for (int k = 0; k < 10; ++k) {
				if (Word[widx][k] == '\0') break;
				subjectStr[pos++] = Word[widx][k];
			}
			subjectStr[pos++] = ' ';
		}
		subjectStr[pos - 1] = '\0';

		return usersolution.deleteMail(uid, subjectStr);
	}
	
	private static int run(int answer) throws Exception {
		int Q, K, cmd, sample, seed, param1, param2, ret;
		int uid, rcnt;
		char buf[] = new char [30];
		
		String inputStr;		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		Q = Integer.parseInt(st.nextToken());
		sample = Integer.parseInt(st.nextToken());
		U = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		if (sample == 0) {
			W = Integer.parseInt(st.nextToken());
			minR = Integer.parseInt(st.nextToken());
			maxR = Integer.parseInt(st.nextToken());
			SW = Integer.parseInt(st.nextToken());
			seed = Integer.parseInt(st.nextToken());
			make_string(seed);
		}

		usersolution.init(U, K);

		for (int i = 1; i < Q; ++i) {
			st = new StringTokenizer(br.readLine(), " ");
			cmd = Integer.parseInt(st.nextToken());
			switch (cmd) {
			case SENDMAIL:
				if (sample == 1) {
					inputStr = st.nextToken();
					uid = Integer.parseInt(st.nextToken());
					rcnt = Integer.parseInt(st.nextToken());
					for (int k = 0; k < rcnt; ++k) rids[k] = Integer.parseInt(st.nextToken());
					for (int k = 0; k < inputStr.length(); ++k) {
						buf[k] = inputStr.charAt(k);
						if (buf[k] == '_') buf[k] = ' ';
					}
					buf[inputStr.length()] = '\0';
					usersolution.sendMail(buf, uid, rcnt, rids);
				}
				else {
					seed = Integer.parseInt(st.nextToken());
					send_mail(seed);
				}
				break;
			case GETCOUNT:
				param1 = Integer.parseInt(st.nextToken());
				param2 = Integer.parseInt(st.nextToken());
				ret = usersolution.getCount(param1);
				if (ret != param2) answer = 0;
				break;
			case DELETEMAIL:
				if (sample == 1) {
					param1 = Integer.parseInt(st.nextToken());
					inputStr = st.nextToken();
					param2 = Integer.parseInt(st.nextToken());
					for (int k = 0; k < inputStr.length(); ++k) {
						buf[k] = inputStr.charAt(k);
						if (buf[k] == '_') buf[k] = ' ';
					}
					buf[inputStr.length()] = '\0';
					ret = usersolution.deleteMail(param1, buf);
                    //System.out.println("delete : " +"ret : " + ret + " param2 : " + param2);
					if (ret != param2) answer = 0;
				}
				else {
					param1 = Integer.parseInt(st.nextToken());
					seed = Integer.parseInt(st.nextToken());
					param2 = Integer.parseInt(st.nextToken());
					ret = delete_mail(param1, seed);
                    //System.out.println("delete : " + "ret : " + ret + " param2 : " + param2);
					if (ret != param2) answer = 0;
				}
				break;
			case SEARCHMAIL:
				param1 = Integer.parseInt(st.nextToken());
				inputStr = st.nextToken();
				param2 = Integer.parseInt(st.nextToken());
				for (int k = 0; k < inputStr.length(); ++k) {
					buf[k] = inputStr.charAt(k);
				}
				buf[inputStr.length()] = '\0';
				ret = usersolution.searchMail(param1, buf);
                //System.out.println("search : " + "ret : " + ret + " param2 : " + param2);
				if (ret != param2) answer = 0;
				break;
			default:
				break;
			}
		}

		return answer;
	}

	public static void main(String[] args) throws Exception {
		int T, Mark;

		System.setIn(new java.io.FileInputStream("swea2022/sample_input (1).txt"));
		br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer stinit = new StringTokenizer(br.readLine(), " ");
		T = Integer.parseInt(stinit.nextToken());
		Mark = Integer.parseInt(stinit.nextToken());
		
		for (int tc = 1; tc <= T; tc++) {
			System.out.println("#" + tc + " " + run(Mark));
		}
		
		br.close();
	}
}