public class Rectangle {
    private double top;
    private double bottom;
    private double left;
    private double right;

    public void setBottomTop(double newBottom, double newTop) throws Exception
    {
        if(newBottom > newTop)
        {
            System.out.println("Error: Bottom and Top in wrong order!");
            throw new Exception();
        }
        else {
            this.bottom = newBottom;
            this.top = newTop;
        }
    }

    public void setLeftRight(double newLeft, double newRight) throws Exception
    {
        if(newLeft > newRight)
        {
            System.out.println("Error: Left and Right in wrong order!");
            throw new Exception();
        }
        else {
            this.left = newLeft;
            this.right = newRight;
        }
    }

    public void setTop(double newTop) throws Exception
    {
        if( this.bottom > newTop )
        {
            System.out.println("Error: Bottom and Top in wrong order!");
            throw new Exception();
        }
        else this.top = newTop;
    }

    public void setBottom(double newBottom) throws Exception
    {
        if(newBottom > this.top)
        {
            System.out.println("Error: Bottom and Top in wrong order!");
            throw new Exception();
        }
        else this.bottom = newBottom;
    }

    public void setLeft(double newLeft) throws Exception
    {
        if(newLeft > this.right)
        {
            System.out.println("Error: Left and Right in wrong order!");
            throw new Exception();
        }
        else this.left = newLeft;
    }

    public void setRight(double newRight) throws Exception
    {
        if(this.left > newRight)
        {
            System.out.println("Error: Right and Left in wrong order!");
            throw new Exception();
        }
        else this.right = newRight;
    }

    public Rectangle(double left, double right, double top, double bottom)
    {
        try {
            setBottomTop(bottom, top);
            setLeftRight(left, right);
        } catch(Exception e) {
            this.left = 1;
            this.right = 2;
            this.bottom = 1;
            this.top = 1;
        }
    }

    public Rectangle()
    {
        this.top = 2;
        this.bottom = 1;
        this.left = 1;
        this.right = 2;
    }

    public double getTop() {return this.top;}
    public double getBottom() {return this.bottom;}
    public double getLeft() {return this.left;}
    public double getRight() {return this.right;}

    public double getHeight()
    {
        return this.top - this.bottom;
    }

    public double getWidth()
    {
        return this.right - this.left;
    }

    public double getArea()
    {
        return getHeight() * getWidth();
    }

    public boolean insideRectangle(double x, double y)
    {
        boolean result = true;

        if(x < this.left || x > this.right) result = false;
        if(y < this.bottom || y > this.top) result = false;

        return result;
    }
}
