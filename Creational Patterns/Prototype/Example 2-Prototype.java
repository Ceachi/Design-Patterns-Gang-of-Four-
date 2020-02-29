
//PrototypeCapable

package com.howtodoinjava.prototypeDemo.contract;
 
public interface PrototypeCapable extends Cloneable
{
    public PrototypeCapable clone() throws CloneNotSupportedException;
}


//Movie.java, Album.java and Show.java


package com.howtodoinjava.prototypeDemo.model;
 
import com.howtodoinjava.prototypeDemo.contract.PrototypeCapable;
 
public class Movie implements PrototypeCapable
{
    private String name = null;
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    @Override
    public Movie clone() throws CloneNotSupportedException {
        System.out.println("Cloning Movie object..");
        return (Movie) super.clone();
    }
    @Override
    public String toString() {
        return "Movie";
    }
}
 
public class Album implements PrototypeCapable
{
    private String name = null;
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    @Override
    public Album clone() throws CloneNotSupportedException {
        System.out.println("Cloning Album object..");
        return (Album) super.clone();
    }
    @Override
    public String toString() {
        return "Album";
    }
}
 
public class Show implements PrototypeCapable
{
    private String name = null;
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    @Override
    public Show clone() throws CloneNotSupportedException {
        System.out.println("Cloning Show object..");
        return (Show) super.clone();
    }
    @Override
    public String toString() {
        return "Show";
    }
}


//PrototypeFactory.java

package com.howtodoinjava.prototypeDemo.factory;
 
import com.howtodoinjava.prototypeDemo.contract.PrototypeCapable;
import com.howtodoinjava.prototypeDemo.model.Album;
import com.howtodoinjava.prototypeDemo.model.Movie;
import com.howtodoinjava.prototypeDemo.model.Show;
 
public class PrototypeFactory
{
    public static class ModelType
    {
        public static final String MOVIE = "movie";
        public static final String ALBUM = "album";
        public static final String SHOW = "show";
    }
    private static java.util.Map<String , PrototypeCapable> prototypes = new java.util.HashMap<String , PrototypeCapable>();
 
    static
    {
        prototypes.put(ModelType.MOVIE, new Movie());
        prototypes.put(ModelType.ALBUM, new Album());
        prototypes.put(ModelType.SHOW, new Show());
    }
 
    public static PrototypeCapable getInstance(final String s) throws CloneNotSupportedException {
        return ((PrototypeCapable) prototypes.get(s)).clone();
    }
}


//TestPrototypePattern


package com.howtodoinjava.prototypeDemo.client;
 
import com.howtodoinjava.prototypeDemo.factory.PrototypeFactory;
import com.howtodoinjava.prototypeDemo.factory.PrototypeFactory.ModelType;
 
public class TestPrototypePattern
{
    public static void main(String[] args)
    {
        try
        {
            String moviePrototype  = PrototypeFactory.getInstance(ModelType.MOVIE).toString();
            System.out.println(moviePrototype);
 
            String albumPrototype  = PrototypeFactory.getInstance(ModelType.ALBUM).toString();
            System.out.println(albumPrototype);
 
            String showPrototype  = PrototypeFactory.getInstance(ModelType.SHOW).toString();
            System.out.println(showPrototype);
 
        }
        catch (CloneNotSupportedException e)
        {
            e.printStackTrace();
        }
    }
}


//OUTPUT

Cloning Movie object..
Movie
Cloning Album object..
Album
Cloning Show object..
Show