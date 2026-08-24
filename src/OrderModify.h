#pragma once

#include "Order.h"

class OrderModify {
  public:
    OrderModify(OrderId id, OrderDirection direction, Price price,
                Quantity quantity)
        : id_{id}, direction_{direction}, price_{price}, quantity_{quantity} {}

    OrderId GetOrderId() const { return id_; }
    OrderDirection GetOrderDirection() const { return direction_; }
    Price GetPrice() const { return price_; }
    Quantity GetQuantity() const { return quantity_; }

    OrderPointer ToOrderPointer(OrderType type) const {
        return std::make_shared<Order>(type, GetOrderId(), GetOrderDirection(),
                                       GetPrice(), GetQuantity());
    }

  private:
    OrderId id_;
    OrderDirection direction_;
    Price price_;
    Quantity quantity_;
};
