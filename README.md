<h1 style="font-size: 28px;">SimpleDiary - C++ 加密日記系統</h1>

<p>本專案為課堂 C++ 作業，實作一個簡易的加密日記系統。</p>
<p>使用者可透過密碼加密文字並儲存至檔案，再透過相同密碼成功解密。</p>

<h2 style="font-size: 20px;">系統畫面展示</h2>
<div>
  <img src="SimpleDiary/Diary02.jpg" alt="Screenshot1" width="300" />
  <img src="SimpleDiary/Diary01.jpg" alt="Screenshot2" width="300" />
</div>

<h2>功能介紹與實作邏輯</h2>
<ul>
  <li>
    <strong>1. 寫入加密日記</strong><br/>
    使用者輸入日記內容與密碼（整數），程式將所有字元進行偏移式加密（使用 <code>c + 79 - 密碼</code> 方式）後寫入指定檔案。<br/>
    加密內容前綴 <code>&lt;&lt;CHECK&gt;&gt;</code> 作為驗證用標記，後續解密會比對此段文字判斷密碼正確性。
  </li>
  <li>
    <strong>2. 解密讀取日記</strong><br/>
    讀取檔案後，要求使用者反覆輸入密碼，並嘗試進行逆向解密（<code>c - 79 + 密碼</code>）。<br/>
    若成功還原出 <code>&lt;&lt;CHECK&gt;&gt;</code> 前綴，則顯示解密後的日記內容；否則提示「密碼錯誤，請再試一次」，直到成功為止。
  </li>
  <li>
    <strong>3. 系統錯誤與防呆處理</strong><br/>
    - 檔案不存在會提示重新輸入名稱<br/>
    - 密碼錯誤會重複要求輸入（使用 <code>do...while</code>）<br/>
    - 檔案以二進位格式寫入與讀取（<code>ios::binary</code>），避免遇到換行或特殊字元損毀內容
  </li>
</ul>

<h2>使用技術</h2>
<ul>
  <li>加解密邏輯使用偏移碼運算 (偏移常數 79 + 密碼反轉)</li>
  <li>自定驗證標記 <code>&lt;&lt;CHECK&gt;&gt;</code> 作為密碼正確性判斷依據</li>
  <li>檔案操作使用 <code>fstream</code> 讀寫二進位資料</li>
  <li>主控邏輯使用 <code>do...while</code> 與 <code>switch-case</code> 控制選單流程</li>
</ul>

<h2>系統流程圖</h2>
<img src="SimpleDiary/Diary_UML.png" alt="Screenshot1" width="700" />
