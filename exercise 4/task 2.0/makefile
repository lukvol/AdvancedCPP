JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
		$(JC) $(JFLAGS) $*.java

CLASSES = \
		Matcher.java \
		LongNumberMatcher.java \
		Driver.java

default: classes

classes: $(CLASSES:.java=.class)

clean:
		$(RM) *.class