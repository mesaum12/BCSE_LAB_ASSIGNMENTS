package com.saurabh.TestingPhaseMode;

import java.util.Date;
import java.sql.*;

public class Offer {
    private String sourceCity;
    private String destinationCity;
    private float discountPercent;
    private java.sql.Date offerStartDate;
    private java.sql.Date offerEndDate;
    private java.sql.Time offerStartTime;
    private java.sql.Time offerEndTime;
    
    public String getSourceCity()
    {
    	return sourceCity;
    }
    public Date getOfferStartDate() {
		return offerStartDate;
	}
	public void setOfferStartDate(java.sql.Date offerStartDate) {
		this.offerStartDate = offerStartDate;
	}
	public Date getOfferEndDate() {
		return offerEndDate;
	}
	public void setOfferEndDate(java.sql.Date offerEndDate) {
		this.offerEndDate = offerEndDate;
	}
	public Time getOfferStartTime() {
		return offerStartTime;
	}
	public void setOfferStartTime(Time offerStartTime) {
		this.offerStartTime = offerStartTime;
	}
	public Time getOfferEndTime() {
		return offerEndTime;
	}
	public void setOfferEndTime(Time offerEndTime) {
		this.offerEndTime = offerEndTime;
	}
	public String getDestinationCity() {
		return destinationCity;
	}
	public float getDiscountPercent() {
		return discountPercent;
	}
	public void setSourceCity(String source)
    {
    	this.sourceCity=source;
    }
    public void setDestinationCity(String dest)
    {
    	this.destinationCity=dest;
    }
    public void setDiscountPercent(float dis)
    {
    	this.discountPercent=dis;
    }
   
    public float getDiscount()
    {
    	return discountPercent;
    }
	
}
