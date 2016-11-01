import java.util.Iterator;
import java.util.Vector;


public class Driver<E> {

	public static void main(String[] args) {
		LongNumberMatcher m = new LongNumberMatcher();
		Driver d = new Driver();
		
		Vector vector = new Vector();
		for(int i=0; i< 10000000; i++){
		vector.add(i);
		}
		
		Iterator i = vector.iterator();
		System.out.println(d.findIf(i,m).toString());
	}

	
	public <E> E findIf(Iterator<E> iter, Matcher<E> matcher){
		while(iter.hasNext()){
			E obj = iter.next();
			if(matcher.match(obj)){
				return obj;
			}
		}
		return null ;
		}
	


}
