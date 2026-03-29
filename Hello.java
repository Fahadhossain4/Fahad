public class Hello{
    public static void main (String[]args){
        int items = 50;
        float costperitem = 9.99f;
        float totalcost = items*costperitem;
        char currency = '$';
        System.out.println("Number of items:"+items);
        System.out.println("Cost per items:"+costperitem+currency);
        System.out.println("Total cost:"+totalcost+currency);   
    }
}