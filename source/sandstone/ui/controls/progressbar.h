/**
 * @file   progressbar.h
 * @brief  Progress Bar Declarations
 * @author harshjayprakash
 * @date   2025-08-04
 ****************************************************************************************/

#ifndef ST_PROGRESSBAR_H
#define ST_PROGRESSBAR_H

#include <windows.h>

/**
 * @brief Progress bar control.
 */
typedef struct _ProgressBar
{
    RECT region;     /**< The progress bar region. */
    POINT position;  /**< The progress bar position. */
    SIZE size;       /**< The progress bar size. */
    SIZE margin;     /**< The progress bar margin. */
    RECT barRegion;  /**< The bar span region. */
    SIZE barMargin;  /**< The bar margin between outline. */
    INT barMaxSize;  /**< The maximum bar size. */
    INT barMaxPoint; /**< The maximum bar coordinate. */
    INT barMinPoint; /**< The minimum bar coordinate. */
    INT barMinValue; /**< The minimum bar value. */
    INT barMaxValue; /**< The maximum bar value. */
    INT barValue;    /**< The current bar value. */
} TProgressBar;

/**
 * @brief Updates progress bar geometry and layout metadata.
 * 
 * @details
 * Sets or updates position, size, margin, and inner bar margins. Computes the full
 * `region` and `barRegion` rectangles based on provided layout hints. If any pointer
 * is NULL, the corresponding value is left unchanged.
 * 
 * @param[in, out] pPbar        Pointer to progress bar.
 * @param[in]      pPosition    Pointer to position.
 * @param[in]      pSize        Pointer to the size.
 * @param[in]      pMargin      Pointer to the outer margin.
 * @param[in]      pBarMargin   Pointer to the inner bar margin.
 * @return `1` on success, `0` on failure.
 * 
 * @remarks
 * - This function must be called with all arguments for control initialisation.
 */
int stProgressBarUpdateEx(TProgressBar *pPbar, const POINT *pPosition, const SIZE *pSize,
                          const SIZE *pMargin, const SIZE *pBarMargin);

/**
 * @brief Shorthand for updating progress bar position only.
 * 
 * @details
 * Delegates to `stProgressBarUpdateEx` with other layout inputs as NULL.
 * 
 * @param[in, out] pPbar       Pointer to progress bar.
 * @param[in]      pPosition   Pointer to new position.
 * @return `1` on success, `0` on failure.
 * 
 * @remarks
 * - For initialisation please use the `stProgressBarUpdateEx` function.
 */
int stProgressBarUpdate(TProgressBar *pPbar, const POINT *pPosition);

/**
 * @brief Updates the minmax values and current progress.
 * 
 * @details
 * Internally calls the `stProgressBarUpdateMinMax` followed by the
 * `stProgressBarUpdateValue`.
 * 
 * @param[in, out] pPbar      Pointer to progress bar.
 * @param[in]      minValue   Minimum value.
 * @param[in]      maxValue   Maximum value.
 * @param[in]      value      Current value.
 * @return `1` on success, `0` on failure.
 */
int stProgressBarUpdateValueEx(TProgressBar *pPbar, const int minValue,
                               const int maxValue, const int value);

/**
 * @brief Sets progress bar minimum and maximum value ranges.
 * 
 * @details
 * Updates `barMinValue` and `barMaxValue` fields.
 * 
 * @param[in, out] pPbar      Pointer to progress bar.
 * @param[in]      minValue   Minimum value.
 * @param[in]      maxValue   Maximum value.
 * @return `1` on success, `0` on failure.
 */
int stProgressBarUpdateMinMax(TProgressBar *pPbar, const int minValue,
                              const int maxValue);

/**
 * @brief Updates progress bar fill based on current value.
 * 
 * @details
 * Sets `barValue`, computes fill percentage, and adjust `barRegion.right` to reflect
 * the change. Assumes that the min and max values are set.
 * 
 * @param[in, out] pPbar   Pointer to progress bar.
 * @param[in]      value   Minimum value.
 * @return `1` on success, `0` on failure.
 */
int stProgressBarUpdateValue(TProgressBar *pPbar, const int value);

#endif /* ST_PROGRESSBAR_H */