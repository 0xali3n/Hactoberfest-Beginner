import java.util.ArrayList;
import java.util.LinkedList;

public class directedgraph {
public static int N = 8;
    public static ArrayList < Integer > [] graph;

	public static void main(String[] args) {
		graph= new ArrayList[N];
		for(int i=0;i<graph.length;i++)
		{
			graph[i]=new ArrayList<>();
		}
	    graph[7].add(5);
		graph[7].add(6);
		graph[5].add(4);
		graph[5].add(2);
		graph[6].add(4);
		graph[6].add(3);
		graph[2].add(1);	
		graph[3].add(1);	
		graph[1].add(0);
		

		//topologicalsort();
		KahnsAlgo();
		//topologicalsortcycle();
		display();
	}

     public static void display()
	 {
		 for(int i=0;i<graph.length;i++)
		 {
			 System.out.print(i+"->");
			 for(Integer e: graph[i])
			 {
				 System.out.print(e+" ");
			 }
			 System.out.println();
		 }
	 }
	public static class Edge {
		int v = 0;
		int w = 0;

		Edge(int v, int w) {
			this.v = v;
			this.w = w;
		}
	}

	public static void topologicalsort_(int src, boolean[] vis, ArrayList<Integer> ans)
	{
		vis[src]=true;

		for(Integer e: graph[src])

		{
			if(!vis[e])
			{
				topologicalsort_(e,vis,ans);
			}
		}
		ans.add(src);
	}

  public static void topologicalsort()
  {

  	boolean[] vis=new boolean[N];

  	ArrayList<Integer> ans= new ArrayList<>();

  	for(int i=0;i<N;i++)
  	{
  		if(!vis[i])
  		{
  			topologicalsort_(i,vis,ans);
  		}
  	}
      
	  System.out.println(ans);
  }

   public static void KahnsAlgo()
   {
	int[] indegree=new int[N];

	for(int i=0;i<N;i++)
	{
		for(Integer e: graph[i])
		{
			indegree[e]++;
		}
	}

	LinkedList<Integer> que= new LinkedList<>();

	for(int i=0;i<N;i++)
	{
		if(indegree[i]==0)
		que.addLast(i);
	}
    ArrayList<Integer> ans=new ArrayList<>();
	while(que.size()!=0)
	{
		int sz=que.size();
		while(sz-- >0)
		{
			int rvtx=que.removeFirst();
			ans.add(rvtx);

			for(Integer e: graph[rvtx])
			{
				indegree[e]--;
				if(indegree[e]==0)
				que.addLast(e);
			}
		}
	}

	if(ans.size()!=N)
	{
		System.out.println("cycle");
	}
	else{
		System.out.println(ans);
	}
   }


public static boolean topologicalsortcycle_(int src, int[] vis, ArrayList<Integer> ans)
{
	if(vis[src]==1) return true; //cycle
	if(vis[src]==2) return false; // no cycle

	boolean res=false;

	vis[src]=1;
	ans.add(src);
     for(Integer e: graph[src])
	 {
		 res=res|| topologicalsortcycle_(e,vis,ans);
	 }

	vis[src]=2;
	return res;
}
  
  public static void topologicalsortcycle()
  {
	  int[] vis=new int[N];
	  ArrayList<Integer> ans=new ArrayList<>();
	  boolean res=false;
	  

	  for(int i=0;i<N && !res;i++)
	  {
		  if(vis[i]==0)
		  res=res||topologicalsortcycle_(i, vis,ans);
	  }

	  if(res)
	  {
		  System.out.println("cycle");
	  }
	  else{
		  System.out.println(ans);
	  }
  }

  public static void SCC()  //strongly connected components
}

 
	
   