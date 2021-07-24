package test;


/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args )
    {
        qtcc dd = new qtcc();
        System.out.println( dd.printhellp("hello world").toString() );
    }
}


class qtcc{
    public String[] printhellp(String f){
        return f.split("");
    }
}
