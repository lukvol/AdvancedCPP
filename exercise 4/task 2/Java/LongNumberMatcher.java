
public class LongNumberMatcher<E> implements Matcher<E> {

	
	@Override
	public boolean match(E elem) {
		if(elem.equals(5111111)){
			return true;
		}
		
		return false;
	}

	
	
	
}
