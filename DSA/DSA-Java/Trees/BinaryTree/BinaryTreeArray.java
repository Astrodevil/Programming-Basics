//Binary Tree using array
public class BinaryTreeArray{
	public static void main(String argd[]){
		Tree bt = new Tree();
		bt.Root("A");
        bt.setLeft("B", 0);
        bt.setRight("C", 0);
        bt.setLeft("D", 1);
        bt.setRight("E", 1);
        bt.setLeft("F", 2);
        bt.print();	
	}
}

class Tree{
	static int root = 0;
	String[] str = new String[10];

	public void Root(String root){
		str[0] = root;
	}

	public void setLeft(String key, int root){
		int t = (root*2)+1;
		if(str[root]==null){
			System.out.printf("Can't set child at %d, no parent found. \n", t);
		}
		else{
			str[t] = key;
		}
	}

	public void setRight(String key, int root){
		int t = (root*2)+2;
		if(str[root]==null){
			System.out.printf("Can't set child at %d, no parent found. \n", t);
		}
		else{
			str[t] = key;
		}
	}
	public void print(){
		for(int i = 0; i < 10; i++){
			if(str[i]!=null){
				System.out.print(str[i]);
			}
			else{
				System.out.print("-");
			}
		}
	}
}