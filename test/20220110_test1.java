package test;

import java.util.*;

class Pair<T, E> {
    int first;
    int second;

    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}


class Buy implements Comparable<Buy> {
    int mNumber;
    int mStock;
    int mQuantity;
    int mPrice;

    public Buy(int mNumber, int mStock, int mQuantity, int mPrice) {
        this.mNumber = mNumber;
        this.mStock = mStock;
        this.mQuantity = mQuantity;
        this.mPrice = mPrice;
    }

    @Override
    public int compareTo(Buy buy) {
        if (this.mPrice > buy.mPrice) return -1;
        else if (this.mPrice < buy.mPrice) return 1;
        else {
            if (this.mNumber <= buy.mNumber) return -1;
            else return 1;
        }
    }
}

class Sell implements Comparable<Sell>{
    int mNumber;
    int mStock;
    int mQuantity;
    int mPrice;

    public Sell(int mNumber, int mStock, int mQuantity, int mPrice) {
        this.mNumber = mNumber;
        this.mStock = mStock;
        this.mQuantity = mQuantity;
        this.mPrice = mPrice;
    }

    @Override
    public int compareTo(Sell sell) {
	    if (this.mPrice > sell.mPrice) return 1;
	    else if (this.mPrice < sell.mPrice) return -1;
	    else {
	        if (this.mNumber <= sell.mNumber) return -1;
	        else return 1;
	    }
	}
}

class UserSolution
{
    LinkedList<Sell> sellTable[] = new LinkedList[6];
    LinkedList<Buy> buyTable[] = new LinkedList[6];
    LinkedList<Integer> assignTable[] = new LinkedList[6];
    ArrayList<Integer> assignDpTable[] = new ArrayList[6];
    HashMap<Integer, Pair<Integer, Pair<Integer, Integer> > > numberMap = new HashMap();

	public void init()
	{
        for (int i = 0; i <= 5; i++) {
            sellTable[i] = new LinkedList<Sell>();
            buyTable[i] = new LinkedList<Buy>();
            assignTable[i] = new LinkedList<Integer>();
            assignDpTable[i] = new ArrayList<Integer>();
        }
	}
	
	public int buy(int mNumber, int mStock, int mQuantity, int mPrice)
	{
        LinkedList<Buy> buyStockTable = buyTable[mStock];
        LinkedList<Sell> sellStockTable = sellTable[mStock];
        Buy buy = new Buy(mNumber, mStock, mQuantity, mPrice);
        

        if (sellStockTable.isEmpty() || (!sellStockTable.isEmpty() && sellStockTable.get(0).mPrice > mPrice)){
            buyStockTable.add(buy);
            numberMap.put(mNumber, new Pair(0, buyStockTable.size() - 1));
            Collections.sort(buyStockTable);
        } else {

            while (buy.mQuantity > 0) {
                if (sellStockTable.size() <= 0) break;
                if (sellStockTable.get(0).mPrice > mPrice) break;
                
                assignTable[mStock].add(sellStockTable.get(0).mPrice);

                if (sellStockTable.get(0).mQuantity <= buy.mQuantity) {
                    buy.mQuantity = buy.mQuantity - sellStockTable.get(0).mQuantity;
                    sellStockTable.remove(0);
                } else {
                    sellStockTable.get(0).mQuantity = sellStockTable.get(0).mQuantity - buy.mQuantity;
                    buy.mQuantity = 0;
                }
            }

            if (buy.mQuantity > 0) {
                buyStockTable.add(buy);
                numberMap.put(mNumber, new Pair(0, buyStockTable.size() - 1));
                Collections.sort(buyStockTable);
            }
        }

		return buy.mQuantity;
	}
	
	public int sell(int mNumber, int mStock, int mQuantity, int mPrice)
	{
        LinkedList<Buy> buyStockTable = buyTable[mStock];
        LinkedList<Sell> sellStockTable = sellTable[mStock];
        Sell sell = new Sell(mNumber, mStock, mQuantity, mPrice);

        if (buyStockTable.isEmpty() || (!buyStockTable.isEmpty() && buyStockTable.get(0).mPrice < mPrice)) {
            sellStockTable.add(sell);
            numberMap.put(mNumber, new Pair(1, sellStockTable.size() - 1));
            Collections.sort(sellStockTable);
        } else {
            while (sell.mQuantity > 0) {
                if (buyStockTable.size() <= 0) break;
                if (buyStockTable.get(0).mPrice < mPrice) break;
                
                assignTable[mStock].add(buyStockTable.get(0).mPrice);

                if (buyStockTable.get(0).mQuantity <= sell.mQuantity) {
                    sell.mQuantity = sell.mQuantity - buyStockTable.get(0).mQuantity;
                    buyStockTable.remove(0);
                } else {
                    buyStockTable.get(0).mQuantity = buyStockTable.get(0).mQuantity - sell.mQuantity;
                    sell.mQuantity = 0;
                }
            }

            if (sell.mQuantity > 0) {
                sellStockTable.add(sell);
                numberMap.put(mNumber, new Pair(1, sellStockTable.size() - 1));
                Collections.sort(sellStockTable);
            }
        }
    

		return sell.mQuantity;
	}

	public void cancel(int mNumber)
	{
        if (numberMap.get(mNumber).first == 0) {
            buyTable[]
        }

        for (int i = 0; i <= 5; i++) {
            for (int j = 0; j < buyTable[i].size(); j++) {
                if (buyTable[i].get(j).mNumber == mNumber) {
                    buyTable[i].remove(buyTable[i].get(j));
                    return;
                }
            }

            for (int j = 0; j < sellTable[i].size(); j++) {
                if (sellTable[i].get(j).mNumber == mNumber) {
                    sellTable[i].remove(sellTable[i].get(j));
                    return;
                }
            }
        }
 	}
	
	public int bestProfit(int mStock)
	{
        int maxPrice = 0;
        for (int i = 0; i < assignTable[mStock].size(); i++) {
            for (int j = 0; j < i; j++) {
                maxPrice = Math.max(maxPrice, assignTable[mStock].get(i) - assignTable[mStock].get(j));
            }
        }
		return maxPrice;
	}
}