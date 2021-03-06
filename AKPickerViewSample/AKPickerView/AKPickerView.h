//
//  AKPickerView.h
//  AKPickerViewSample
//
//  Created by Akio Yasui on 3/29/14.
//  Copyright (c) 2014 Akio Yasui. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, AKPickerViewStyle) {
    AKPickerViewStyle3D = 1,
    AKPickerViewStyleFlat
};

typedef NS_ENUM(BOOL, AKPickerTypeSelector) {
    AKPickerTypeSelectorImage,
    AKPickerTypeSelectorTitle
};

@class AKPickerView;

@protocol AKPickerViewDataSource <NSObject>
@required
- (NSUInteger)numberOfItemsInPickerView:(AKPickerView *)pickerView;
@optional
- (NSString *)pickerView:(AKPickerView *)pickerView titleForItem:(NSInteger)item;
- (UIImage *)pickerView:(AKPickerView *)pickerView imageForItem:(NSInteger)item;
- (AKPickerTypeSelector)pickerView:(AKPickerView *)pickerView typeForItem:(NSInteger)item;

@end

@protocol AKPickerViewDelegate <UIScrollViewDelegate>
@optional
- (void)pickerView:(AKPickerView *)pickerView didSelectItem:(NSInteger)item;
- (CGSize)pickerView:(AKPickerView *)pickerView marginForItem:(NSInteger)item;
- (void)pickerView:(AKPickerView *)pickerView configureLabel:(UILabel * const)label forItem:(NSInteger)item;
- (BOOL)pickerView:(AKPickerView *)pickerView selectableItem:(NSInteger)item;
@end

@interface AKPickerView : UIView

@property (nonatomic, weak) id <AKPickerViewDataSource> dataSource;
@property (nonatomic, weak) id <AKPickerViewDelegate> delegate;
@property (nonatomic, strong) UIFont *font;
@property (nonatomic, strong) UIFont *highlightedFont;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIColor *highlightedTextColor;
@property (nonatomic, assign) CGFloat interitemSpacing;
@property (nonatomic, assign) CGFloat fisheyeFactor; // 0...1; slight value recommended such as 0.0001
@property (nonatomic, assign, getter=isMaskDisabled) BOOL maskDisabled;
@property (nonatomic, assign) BOOL imagesNotSelectable;
@property (nonatomic, assign) AKPickerViewStyle pickerViewStyle;
@property (nonatomic, assign, readonly) NSUInteger selectedItem;
@property (nonatomic, assign, readonly) CGPoint contentOffset;
@property (nonatomic, strong) UICollectionView *collectionView;

- (void)reloadData;
- (void)scrollToItem:(NSUInteger)item animated:(BOOL)animated;
- (void)selectItem:(NSUInteger)item animated:(BOOL)animated;
- (void)selectItem:(NSUInteger)item animated:(BOOL)animated notifySelection:(BOOL)notifySelection;
- (void)didEndScrolling;

@end
