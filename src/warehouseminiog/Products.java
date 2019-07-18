/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package warehouseminiog;

public class Products {
    
    private String pid;
    private String pname;
    private String quantity;
    private int price;
    private String category;
    
    public Products(String PID, String Pname, int Price, String Category,String Quantity)
    {
        this.pid = PID;
        this.pname = Pname;
        this.quantity = Quantity;
        this.price = Price;
        this.category = Category;
    }
    
    public String getId()
    {
        return pid;
    }
    
    public String getPname()
    {
        return pname;
    }
    
    public String getQuantity()
    {
        return quantity;
    }
    
    public int getPrice()
    {
        return price;
    }
    
    public String getCategory()
    {
        return category;
    }
}


