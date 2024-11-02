public class Example {
    public static void main(String[] args) {
        int x = 5;
        int y = 10;
        int result = x + y;

        System.out.println("Результат: " + result);

        if (result > 10) {
            System.out.println("Результат больше 10");
        }

        String name = "Иван";
        System.out.println("Привет, " + name + "!");

        // комментарий, который не используется
        // System.out.println("Это строка, которая не используется");

        int[] array = new int[5];
        array[0] = 1;
        array[1] = 2;
        array[2] = 3;
        array[3] = 4;
        array[4] = 5;

        for (int i = 0; i < array.length; i++) {
            System.out.println("Элемент " + i + ": " + array[i]);
        }
    }
}