import java.util.Arrays;

class Main{

    public static boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        boolean widthIsPositive = Math.min(rec1[2], rec2[2]) > Math.max(rec1[0], rec2[0]);
        boolean heightIsPositive = Math.min(rec1[3], rec2[3]) > Math.max(rec1[1], rec2[1]);
        return ( widthIsPositive && heightIsPositive);
    }

    public static void main(String[] args) {
        int[] rec1 = {1,1,5,5};
        int[] rec2 = {1,7,10,12};

        System.out.println("Rectange 1 - " + Arrays.toString(rec1));
        System.out.println("Rectange 2 - " + Arrays.toString(rec2));
        boolean isOverlapping = isRectangleOverlap(rec1, rec2);
        System.out.println(isOverlapping?"The rectangles are overlapping":"The rectangles are not overlapping");
    }
}
