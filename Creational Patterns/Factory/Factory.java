/*



- Factory pattern
- nu merge, trebuie puse in fisiere separate

*/

public class Main {
    
    
    public enum ShapeType {
        CIRCLE, SQUARE, RECTANGLE;
    }
    
    public interface Shape {
        void draw();
    }
    
    
    public class Circle implements Shape {
        
        public void draw() {
            System.out.println("Drawing Circle");
        }
    }
    
    public class Square implements Shape {
        
        public void draw() {
            System.out.println("Drawing Square");
        }
    }
    
    public class Rectangle implements Shape {
        
        public void draw() {
            System.out.println("Drawing Rectangle");
        }
    }
    
    public class ShapeFactory {
        
        Shape getShape(ShapeType type) {
            if(type == ShapeType.CIRCLE) 
                return new Circle();
            
        }
    }
    
    
    public static void main(String[] args) {
    		ShapeFactory factory = new ShapeFactory();
    		
    		Shape obj = factory.getShape(ShapeType.CIRCLE);
    }
}


