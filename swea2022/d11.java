package swea2022;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.StringTokenizer;

class UserSolution_d11 {

    class Pos {
        int x, y;
        public Pos(int x, int y) { this.x = x; this.y = y; }
    }

    class PosY implements Comparable<PosY> {
        int x, pID;
        public PosY(int x, int pID) { this.x = x; this.pID = pID; }

        @Override
        public int compareTo(PosY o) {
            if (x < o.x) return -1;
            else if (x == o.x) return 0;
            else return 1;
        }
    }

    class PosX implements Comparable<PosX> {
        int y, pID;
        public PosX(int y, int pID) { this.y = y; this.pID = pID; }

        @Override
        public int compareTo(PosX o) {
            if (y < o.y) return -1;
            else if (y == o.y) return 0;
            else return 1;
        }
    }

    class PosXY implements Comparable<PosXY> {
        int x, y, pID;
        public PosXY(int x, int y, int pID) { this.x = x; this.y = y; this.pID = pID; }

        @Override
        public int compareTo(PosXY o) {
            if (x < o.x) return -1;
            else if (x == o.x) return 0;
            else return 1;
        }
    }

    int[] isInfect = new int[50010];
    ArrayList<Integer>[] infector = new ArrayList[50010];

    // x -> y, pID
    HashMap<Integer, ArrayList<PosX>> mapx = new HashMap<>();

    // y -> x, pID
    HashMap<Integer, ArrayList<PosY>> mapy = new HashMap<>();

    // x + y -> x, y, pID
    HashMap<Integer, ArrayList<PosXY>> mapxy1 = new HashMap<>();

    // y - x -> x, y, pID
    HashMap<Integer, ArrayList<PosXY>> mapxy2 = new HashMap<>();

    // pID -> x, y
    HashMap<Integer, Pos> mapInfo = new HashMap<>();

    int[][] dir = new int[][] { {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1} };

	void init() {
        for (int i = 0; i <= 50000; i++) {
            if (infector[i] == null) infector[i] = new ArrayList<>();
            else infector[i].clear();
            isInfect[i] = 0;
        }
        
        mapx.clear();
        mapy.clear();
        mapxy1.clear();
        mapxy2.clear();
        mapInfo.clear();
	}

	void addPlace(int pID, int r, int c) {
        if (!mapx.containsKey(c)) {
            ArrayList<PosX> list = new ArrayList<>();
            list.add(new PosX(r, pID));
            mapx.put(c, list);
        } else {
            mapx.get(c).add(new PosX(r, pID));
            Collections.sort(mapx.get(c));
        }
        
        if (!mapy.containsKey(r)) {
            ArrayList<PosY> list = new ArrayList<>();
            list.add(new PosY(c, pID));
            mapy.put(r, list);
        } else {
            mapy.get(r).add(new PosY(c, pID));
            Collections.sort(mapy.get(r));
        }

        if (!mapxy1.containsKey(r + c)) {
            ArrayList<PosXY> list = new ArrayList<>();
            list.add(new PosXY(c, r, pID));
            mapxy1.put(r + c, list);
        } else {
            mapxy1.get(r + c).add(new PosXY(c, r, pID));
            Collections.sort(mapxy1.get(r + c));
        }

        if (!mapxy2.containsKey(r - c)) {
            ArrayList<PosXY> list = new ArrayList<>();
            list.add(new PosXY(c, r, pID));
            mapxy2.put(r - c, list);
        } else {
            mapxy2.get(r - c).add(new PosXY(c, r, pID));
            Collections.sort(mapxy2.get(r - c));
        }

        mapInfo.put(pID, new Pos(c, r));
	}

	void removePlace(int pID) {
        int col = mapInfo.get(pID).x;
        int row = mapInfo.get(pID).y;
        isInfect[pID] = 0;

        Iterator<PosX> it1 = mapx.get(col).iterator();
        while (it1.hasNext()) {
            PosX p = it1.next();
            if (p.pID == pID) { it1.remove(); break; }
        }

        Iterator<PosY> it2 = mapy.get(row).iterator();
        while (it2.hasNext()) {
            PosY p = it2.next();
            if (p.pID == pID) { it2.remove(); break; }
        }

        Iterator<PosXY> it3 = mapxy1.get(col + row).iterator();
        while (it3.hasNext()) {
            PosXY p = it3.next();
            if (p.pID == pID) { it3.remove(); break; }
        }

        Iterator<PosXY> it4 = mapxy2.get(row - col).iterator();
        while (it4.hasNext()) {
            PosXY p = it4.next();
            if (p.pID == pID) { it4.remove(); break; }
        }

        mapInfo.remove(pID);
	}

	void contactTracing(int uID, int visitNum, int moveInfo[], int visitList[]) {
        int startPos = moveInfo[0];
        int sx = mapInfo.get(startPos).x, sy = mapInfo.get(startPos).y;
        visitList[0] = startPos;

        HashSet<Integer> uidSet = new HashSet<>();
        uidSet.add(startPos);
        for (int i = 1; i < visitNum; i++) {
            int[] visit = isVisit(sx, sy, moveInfo[i]);
            if (visit[0] > -1) {
                visitList[i] = visit[0]; sx = visit[1]; sy = visit[2];
                uidSet.add(visit[0]);
            }
        }

        Iterator<Integer> siter = uidSet.iterator();
        while (siter.hasNext()) {
            int p = siter.next();
            isInfect[p]++;
            infector[uID].add(p);
        }
	}

	void disinfectPlaces(int uID) {
        Iterator<Integer> iter = infector[uID].iterator();
        while (iter.hasNext()) {
            int pid = iter.next();
            if (mapInfo.containsKey(pid)) isInfect[pid] = 0;
            iter.remove();
        }
	}

    int[] isVisit(int x, int y, int d) {
        int[] ans = new int[3];
        int nx = x + dir[d][0], ny = y + dir[d][1];
        ans[0] = -1; ans[1] = x; ans[2] = y;

        if (nx == x) {
            ArrayList<PosX> mx = mapx.get(x);
            for (int i = 0; i < mx.size(); i++) {
                if (mx.get(i).y == y) {
                    if (y < ny) {
                        for (int j = i + 1; j < mx.size(); j++) {
                            PosX np = mx.get(j);
                            if (isInfect[np.pID] == 0) {
                                ans[0] = np.pID; ans[1] = x; ans[2] = np.y;
                                return ans;
                            }
                        }
                    } else {
                        for (int j = i - 1; j >= 0; j--) {
                            PosX np = mx.get(j);
                            if (isInfect[np.pID] == 0) {
                                ans[0] = np.pID; ans[1] = x; ans[2] = np.y;
                                return ans;
                            }
                        }
                    }
                }
            }
        }

        else if (ny == y) {
            ArrayList<PosY> my = mapy.get(y);
            for (int i = 0; i < my.size(); i++) {
                if (my.get(i).x == x) {
                    if (x < nx) {
                        for (int j = i + 1; j < my.size(); j++) {
                            PosY np = my.get(j);
                            if (isInfect[np.pID] == 0) {
                                ans[0] = np.pID; ans[1] = np.x; ans[2] = y;
                                return ans;
                            }
                        }
                    } else {
                        for (int j = i - 1; j >= 0; j--) {
                            PosY np = my.get(j);
                            if (isInfect[np.pID] == 0) {
                                ans[0] = np.pID; ans[1] = np.x; ans[2] = y;
                                return ans;
                            }
                        }
                    }
                }
            }
        }
 
        else if (x + y == nx + ny) {
            ArrayList<PosXY> mxy = mapxy1.get(x + y);
            for (int i = 0; i < mxy.size(); i++) {
                if (mxy.get(i).x == x) {
                    if (x < nx) {
                        for (int j = i + 1; j < mxy.size(); j++) {
                            PosXY np = mxy.get(j);
                            if (isInfect[np.pID] == 0) {
                                ans[0] = np.pID; ans[1] = np.x; ans[2] = np.y;
                                return ans;
                            }
                        }
                    } else {
                        for (int j = i - 1; j >= 0; j--) {
                            PosXY np = mxy.get(j);
                            if (isInfect[np.pID] == 0) {
                                ans[0] = np.pID; ans[1] = np.x; ans[2] = np.y;
                                return ans;
                            }
                        }
                    }
                }
            }
        }

        else if (y - x == ny - nx) {
            ArrayList<PosXY> mxy = mapxy2.get(y - x);
            for (int i = 0; i < mxy.size(); i++) {
                if (mxy.get(i).x == x) {
                    if (x < nx) {
                        for (int j = i + 1; j < mxy.size(); j++) {
                            PosXY np = mxy.get(j);
                            if (isInfect[np.pID] == 0) {
                                ans[0] = np.pID; ans[1] = np.x; ans[2] = np.y;
                                return ans;
                            }
                        }
                    } else {
                        for (int j = i - 1; j >= 0; j--) {
                            PosXY np = mxy.get(j);
                            if (isInfect[np.pID] == 0) {
                                ans[0] = np.pID; ans[1] = np.x; ans[2] = np.y;
                                return ans;
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
}

class Solution_d11 {
	private static BufferedReader br;
	private static UserSolution_d11 usersolution = new UserSolution_d11();

	private final static int INIT = 100;
	private final static int ADD_PLACE = 200;
	private final static int REMOVE_PLACE = 300;
	private final static int CONTACT_TRACING = 400;
	private final static int DISINFECT_PLACES = 500;

	private static boolean run() throws Exception {
		boolean ret = false;
		int cmd;
		int pID, uID, r, c, visitNum;
		int moveInfo[] = new int[100];
		int visitList[] = new int[100];
		int ans;

		StringTokenizer stdin = new StringTokenizer(br.readLine(), " ");

		int queryCnt = Integer.parseInt(stdin.nextToken());

		for (int q = 1; q <= queryCnt; q++) {
			stdin = new StringTokenizer(br.readLine(), " ");

			cmd = Integer.parseInt(stdin.nextToken());

			switch (cmd) {
			case INIT:
				usersolution.init();
				ret = true;
				break;
			case ADD_PLACE:
				pID = Integer.parseInt(stdin.nextToken());
				r = Integer.parseInt(stdin.nextToken());
				c = Integer.parseInt(stdin.nextToken());
				usersolution.addPlace(pID, r, c);
				break;
			case REMOVE_PLACE:
				pID = Integer.parseInt(stdin.nextToken());
				usersolution.removePlace(pID);
				break;
			case CONTACT_TRACING:
				uID = Integer.parseInt(stdin.nextToken());
				visitNum = Integer.parseInt(stdin.nextToken());
				stdin = new StringTokenizer(br.readLine(), " ");
				for (int i = 0; i < visitNum; i++)
					moveInfo[i] = Integer.parseInt(stdin.nextToken());
				usersolution.contactTracing(uID, visitNum, moveInfo, visitList);
				stdin = new StringTokenizer(br.readLine(), " ");

                // for (int i = 0; i < visitNum; i++) {
                //     System.out.printf(visitList[i] + " ");
                // }
                // System.out.println("");
                // System.out.println("");

				for (int i = 0; i < visitNum; i++) {
					ans = Integer.parseInt(stdin.nextToken());
                    //System.out.printf(ans + " ");
					if (visitList[i] != ans) {
                        //System.out.printf(" (wrong!) ");
						ret = false;
                    }
				}
                // System.out.println("");
                // System.out.println("");
				break;
			case DISINFECT_PLACES:
				uID = Integer.parseInt(stdin.nextToken());
				usersolution.disinfectPlaces(uID);
				break;
			default:
				ret = false;
				break;
			}
		}

		return ret;
	}

	public static void main(String[] args) throws Exception {
		int T, MARK;

		System.setIn(new java.io.FileInputStream("swea2022/sample_input (1).txt"));
		br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer stinit = new StringTokenizer(br.readLine(), " ");
		T = Integer.parseInt(stinit.nextToken());
		MARK = Integer.parseInt(stinit.nextToken());

		for (int tc = 1; tc <= T; tc++) {
			int score = run() ? MARK : 0;
			System.out.println("#" + tc + " " + score);
		}

		br.close();
	}
}